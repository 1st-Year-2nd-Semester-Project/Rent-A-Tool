-- ============================================
-- Rent-A-Tool — Database Schema & Initial Data
-- MySQL 8.0+
-- ============================================

CREATE DATABASE IF NOT EXISTS rent_a_tool;
USE rent_a_tool;

-- ============================================
-- 1. Users Table (Authentication & User Mgmt)
-- ============================================
DROP TABLE IF EXISTS users;
CREATE TABLE users (
    id         INT AUTO_INCREMENT PRIMARY KEY,
    username   VARCHAR(50)  NOT NULL UNIQUE,
    password   VARCHAR(100) NOT NULL,   -- Salted SHA-256, format: "<saltHex>$<hashHex>" (see Data/PasswordHash.h)
    role       ENUM('Admin', 'Cashier') NOT NULL DEFAULT 'Cashier',
    full_name  VARCHAR(100),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Default accounts (salted SHA-256):
-- admin   / admin123
-- cashier / cashier123
INSERT INTO users (username, password, role, full_name) VALUES
('admin',   '000102030405060708090a0b0c0d0e0f$b38e1e550428e26561b2ae3e1a969b8fc6f4e596d82fd4055de60082dd2d410f', 'Admin',   'Administrator'),
('cashier', '000102030405060708090a0b0c0d0e0f$d5585be436c6216c0e46cc599b29cf6d12c80a46bb5817afbc60237380b41a87', 'Cashier', 'Nimal Perera')
ON DUPLICATE KEY UPDATE password=VALUES(password), role=VALUES(role), full_name=VALUES(full_name);

-- ============================================
-- 2. Tools Table (Inventory)
-- ============================================
DROP TABLE IF EXISTS tools;
CREATE TABLE tools (
    id               INT AUTO_INCREMENT PRIMARY KEY,
    tool_code        VARCHAR(20)   NOT NULL UNIQUE,
    name             VARCHAR(100)  NOT NULL,
    category         VARCHAR(50),
    daily_rate       DECIMAL(10,2) NOT NULL,
    deposit          DECIMAL(10,2) NOT NULL,
    status           ENUM('Available', 'Rented', 'Maintenance', 'Retired', 'Lost') NOT NULL DEFAULT 'Available',
    brand            VARCHAR(50)   NULL,
    model_serial     VARCHAR(50)   NULL,
    condition_status VARCHAR(50)   NULL,
    notes            VARCHAR(255)  NULL,
    created_at       TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

INSERT INTO tools (tool_code, name, category, daily_rate, deposit, status, brand, model_serial, condition_status, notes) VALUES
('T-001', 'Drill Machine',   'Power tools',   800.00,  5000.00, 'Available',   'Bosch',      'GSB 550',     'Excellent', 'Includes 13mm chuck key'),
('T-002', 'Concrete Mixer',  'Construction', 2500.00, 15000.00, 'Rented',      'Honda',      'GX160-MIX',   'Good',      'Heavy duty diesel driven'),
('T-003', 'Angle Grinder',   'Power tools',   600.00,  4000.00, 'Maintenance', 'Makita',     'M0910B',      'Fair',      'Needs guard replacement'),
('T-004', 'Ladder 12ft',     'Construction',  400.00,  3000.00, 'Available',   'Werner',     'AL-12FT',     'Good',      'Aluminum multipurpose'),
('T-005', 'Hedge Trimmer',   'Garden',        500.00,  3500.00, 'Available',   'Black+Decker','GT4245',     'Excellent', 'Corded electric 450W'),
('T-006', 'Pressure Washer', 'Garden',       1200.00,  8000.00, 'Rented',      'Karcher',    'K2 Basic',    'Good',      'Includes spray lance & foam jet')
ON DUPLICATE KEY UPDATE name=VALUES(name), category=VALUES(category), daily_rate=VALUES(daily_rate), deposit=VALUES(deposit), status=VALUES(status);

-- ============================================
-- 3. Customers Table
-- ============================================
DROP TABLE IF EXISTS customers;
CREATE TABLE customers (
    id             INT AUTO_INCREMENT PRIMARY KEY,
    cust_code      VARCHAR(20)  NOT NULL UNIQUE,
    name           VARCHAR(100) NOT NULL,
    nic            VARCHAR(20)  NULL,
    phone          VARCHAR(20)  NULL,
    email          VARCHAR(100) NULL,
    address        VARCHAR(255) NULL,
    is_blacklisted BOOLEAN      NOT NULL DEFAULT FALSE,
    created_at     TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

INSERT INTO customers (cust_code, name, nic, phone, email, address, is_blacklisted) VALUES
('C-001', 'Nimal Perera',   '199012345V', '0771234567', 'nimal@gmail.com',  '12 Galle Road, Colombo 03',     FALSE),
('C-002', 'Kamal Silva',    '198556789V', '0712345678', 'kamal@yahoo.com',  '45 Kandy Road, Kiribathgoda',   TRUE),
('C-003', 'Sunil Fernando', '199245678V', '0759876543', 'sunil@gmail.com',  '78 High Level Road, Maharagama',FALSE)
ON DUPLICATE KEY UPDATE name=VALUES(name), nic=VALUES(nic), phone=VALUES(phone), email=VALUES(email), address=VALUES(address), is_blacklisted=VALUES(is_blacklisted);

-- ============================================
-- 4. Rentals Table
-- ============================================
DROP TABLE IF EXISTS rentals;
CREATE TABLE rentals (
    id           INT AUTO_INCREMENT PRIMARY KEY,
    rental_code  VARCHAR(20)   NOT NULL UNIQUE,
    customer_id  INT           NOT NULL,
    tool_id      INT           NOT NULL,
    rent_date    DATE          NOT NULL,
    due_date     DATE          NOT NULL,
    return_date  DATE          NULL,
    deposit_paid DECIMAL(10,2) NOT NULL DEFAULT 0,
    total_amount DECIMAL(10,2) NOT NULL DEFAULT 0,
    status       ENUM('Active', 'Returned', 'Overdue') NOT NULL DEFAULT 'Active',
    notes        VARCHAR(255)  NULL,
    created_at   TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (customer_id) REFERENCES customers(id),
    FOREIGN KEY (tool_id)     REFERENCES tools(id)
);

INSERT INTO rentals (rental_code, customer_id, tool_id, rent_date, due_date, return_date, deposit_paid, total_amount, status, notes) VALUES
('R-1001', 1, 1, '2026-09-27', '2026-09-30', NULL,         5000.00,  2400.00, 'Active',   'Weekend renovation project'),
('R-1002', 2, 2, '2026-09-20', '2026-09-25', NULL,        15000.00,  7500.00, 'Overdue',  'Customer overdue notification sent'),
('R-1003', 3, 4, '2026-09-28', '2026-10-02', NULL,         3000.00,  1600.00, 'Active',   'Roof repair work'),
('R-1004', 1, 6, '2026-09-15', '2026-09-20', '2026-09-19', 8000.00,  6000.00, 'Returned', 'Returned in good order, deposit refunded')
ON DUPLICATE KEY UPDATE return_date=VALUES(return_date), deposit_paid=VALUES(deposit_paid), total_amount=VALUES(total_amount), status=VALUES(status);

-- ============================================
-- 5. Settings Table
-- ============================================
DROP TABLE IF EXISTS settings;
CREATE TABLE settings (
    `key`   VARCHAR(50)  PRIMARY KEY,
    `value` VARCHAR(255) NOT NULL
);

INSERT INTO settings (`key`, `value`) VALUES
('late_fee_per_day', '200'),
('currency',         'LKR'),
('company_name',     'Rent A Tool'),
('backup_path',      'C:\\RentATool\\Backups')
ON DUPLICATE KEY UPDATE `value`=VALUES(`value`);