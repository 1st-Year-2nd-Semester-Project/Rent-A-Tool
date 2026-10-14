-- ============================================================================
-- Rent-A-Tool: Migration Script for Automated Tool & Customer Codes
-- File: Data/migrate_codes.sql
-- Database: rent_a_tool (MySQL 8.0+)
--
-- PURPOSE:
-- 1. Safely fills in missing or empty codes in 'tools' and 'customers'
--    using the new sequential format (T-0001..., C-0001...).
-- 2. Preserves ALL existing codes untouched (such as T-001..T-007, C-001..C-004)
--    so existing rentals, search queries, and reports are NOT broken.
-- 3. Ensures UNIQUE indexes exist on tools.tool_code and customers.cust_code.
--
-- HOW TO RUN:
-- Option A (MySQL CLI):
--   mysql -u root -p rent_a_tool < Data/migrate_codes.sql
--
-- Option B (PowerShell):
--   & 'C:\Program Files\MySQL\MySQL Server 8.0\bin\mysql.exe' -u root -p rent_a_tool -e "source c:/Users/welcome/Desktop/Rent-A-Tool/Rent-A-Tool/Rent-A-Tool/Data/migrate_codes.sql"
--
-- Option C (MySQL Workbench / phpMyAdmin):
--   Open this file in MySQL Workbench, select the 'rent_a_tool' database, and execute.
-- ============================================================================

USE rent_a_tool;

-- ----------------------------------------------------------------------------
-- Step 1: Ensure columns are NOT NULL and have UNIQUE constraints
-- ----------------------------------------------------------------------------

-- Add UNIQUE index on tools(tool_code) if not already present
SET @tool_idx_exists = (
    SELECT COUNT(*) 
    FROM information_schema.statistics 
    WHERE table_schema = DATABASE() 
      AND table_name = 'tools' 
      AND column_name = 'tool_code' 
      AND non_unique = 0
);

SET @sql_tool_idx = IF(@tool_idx_exists = 0, 
    'ALTER TABLE tools ADD UNIQUE KEY uq_tools_tool_code (tool_code)', 
    'SELECT "tools.tool_code unique constraint already exists" AS status');
PREPARE stmt_tool FROM @sql_tool_idx;
EXECUTE stmt_tool;
DEALLOCATE PREPARE stmt_tool;

-- Add UNIQUE index on customers(cust_code) if not already present
SET @cust_idx_exists = (
    SELECT COUNT(*) 
    FROM information_schema.statistics 
    WHERE table_schema = DATABASE() 
      AND table_name = 'customers' 
      AND column_name = 'cust_code' 
      AND non_unique = 0
);

SET @sql_cust_idx = IF(@cust_idx_exists = 0, 
    'ALTER TABLE customers ADD UNIQUE KEY uq_customers_cust_code (cust_code)', 
    'SELECT "customers.cust_code unique constraint already exists" AS status');
PREPARE stmt_cust FROM @sql_cust_idx;
EXECUTE stmt_cust;
DEALLOCATE PREPARE stmt_cust;

-- ----------------------------------------------------------------------------
-- Step 2: Backfill missing or empty tool_code values
-- ----------------------------------------------------------------------------
DROP PROCEDURE IF EXISTS BackfillMissingToolCodes;
DELIMITER $$
CREATE PROCEDURE BackfillMissingToolCodes()
BEGIN
    DECLARE done INT DEFAULT FALSE;
    DECLARE toolId INT;
    DECLARE nextNum INT;
    DECLARE newCode VARCHAR(20);

    DECLARE cur CURSOR FOR 
        SELECT id FROM tools 
        WHERE tool_code IS NULL OR TRIM(tool_code) = ''
        ORDER BY id ASC;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

    -- Determine base number from existing numeric values
    SELECT IFNULL(MAX(CAST(REGEXP_SUBSTR(tool_code, '[0-9]+') AS UNSIGNED)), 0)
    INTO nextNum
    FROM tools
    WHERE tool_code IS NOT NULL AND TRIM(tool_code) != '';

    OPEN cur;
    read_loop: LOOP
        FETCH cur INTO toolId;
        IF done THEN
            LEAVE read_loop;
        END IF;

        SET nextNum = nextNum + 1;
        SET newCode = CONCAT('T-', LPAD(nextNum, 4, '0'));

        UPDATE tools SET tool_code = newCode WHERE id = toolId;
    END LOOP;
    CLOSE cur;
END$$
DELIMITER ;

CALL BackfillMissingToolCodes();
DROP PROCEDURE IF EXISTS BackfillMissingToolCodes;

-- ----------------------------------------------------------------------------
-- Step 3: Backfill missing or empty cust_code values
-- ----------------------------------------------------------------------------
DROP PROCEDURE IF EXISTS BackfillMissingCustomerCodes;
DELIMITER $$
CREATE PROCEDURE BackfillMissingCustomerCodes()
BEGIN
    DECLARE done INT DEFAULT FALSE;
    DECLARE custId INT;
    DECLARE nextNum INT;
    DECLARE newCode VARCHAR(20);

    DECLARE cur CURSOR FOR 
        SELECT id FROM customers 
        WHERE cust_code IS NULL OR TRIM(cust_code) = ''
        ORDER BY id ASC;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

    -- Determine base number from existing numeric values
    SELECT IFNULL(MAX(CAST(REGEXP_SUBSTR(cust_code, '[0-9]+') AS UNSIGNED)), 0)
    INTO nextNum
    FROM customers
    WHERE cust_code IS NOT NULL AND TRIM(cust_code) != '';

    OPEN cur;
    read_loop: LOOP
        FETCH cur INTO custId;
        IF done THEN
            LEAVE read_loop;
        END IF;

        SET nextNum = nextNum + 1;
        SET newCode = CONCAT('C-', LPAD(nextNum, 4, '0'));

        UPDATE customers SET cust_code = newCode WHERE id = custId;
    END LOOP;
    CLOSE cur;
END$$
DELIMITER ;

CALL BackfillMissingCustomerCodes();
DROP PROCEDURE IF EXISTS BackfillMissingCustomerCodes;

-- ----------------------------------------------------------------------------
-- Verification: Display summary of current codes
-- ----------------------------------------------------------------------------
SELECT 'Tools summary' AS info, COUNT(*) AS total_tools, 
       MIN(tool_code) AS min_code, MAX(tool_code) AS max_code 
FROM tools;

SELECT 'Customers summary' AS info, COUNT(*) AS total_customers, 
       MIN(cust_code) AS min_code, MAX(cust_code) AS max_code 
FROM customers;
