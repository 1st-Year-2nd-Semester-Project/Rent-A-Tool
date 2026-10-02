-- ============================================
-- Rent-A-Tool — Dummy test database
-- MySQL 8.0+
-- ============================================

CREATE DATABASE IF NOT EXISTS rent_a_tool;
USE rent_a_tool;

-- ---------- Users (Login page) ----------
DROP TABLE IF EXISTS users;
CREATE TABLE users (
    id        INT AUTO_INCREMENT PRIMARY KEY,
    username  VARCHAR(50)  NOT NULL UNIQUE,
    password  VARCHAR(255) NOT NULL,   -- plain text for test DB only; hash in production
    role      ENUM('Admin', 'Cashier') NOT NULL DEFAULT 'Cashier',
    full_name VARCHAR(100),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

INSERT INTO users (username, password, role, full_name) VALUES
('admin',   'admin123',   'Admin',   'Chukka Fernando'),
('cashier', 'cashier123', 'Cashier', 'Nimal Perera');

-- ---------- Tools (Inventory page) ----------
DROP TABLE IF EXISTS tools;
CREATE TABLE tools (
    id          INT AUTO_INCREMENT PRIMARY KEY,
    tool_code   VARCHAR(20)  NOT NULL UNIQUE,
    name        VARCHAR(100) NOT NULL,
    category    VARCHAR(50),
    daily_rate  DECIMAL(10,2) NOT NULL,
    deposit     DECIMAL(10,2) NOT NULL,
    status      ENUM('Available', 'Rented', 'Maintenance') NOT NULL DEFAULT 'Available',
    created_at  TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

INSERT INTO tools (tool_code, name, category, daily_rate, deposit, status) VALUES
('T-001', 'Drill Machine',   'Power tools',   800.00,  5000.00, 'Available'),
('T-002', 'Concrete Mixer',  'Construction', 2500.00, 15000.00, 'Rented'),
('T-003', 'Angle Grinder',   'Power tools',   600.00,  4000.00, 'Maintenance'),
('T-004', 'Ladder 12ft',     'Construction',  400.00,  3000.00, 'Available'),
('T-005', 'Hedge Trimmer',   'Garden',        500.00,  3500.00, 'Available'),
('T-006', 'Pressure Washer', 'Garden',       1200.00,  8000.00, 'Rented');

-- ---------- Customers ----------
DROP TABLE IF EXISTS customers;
CREATE TABLE customers (
    id          INT AUTO_INCREMENT PRIMARY KEY,
    cust_code   VARCHAR(20)  NOT NULL UNIQUE,
    name        VARCHAR(100) NOT NULL,
    nic         VARCHAR(20),
    phone       VARCHAR(20),
    is_blacklisted BOOLEAN NOT NULL DEFAULT FALSE,
    created_at  TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

INSERT INTO customers (cust_code, name, nic, phone, is_blacklisted) VALUES
('C-001', 'Nimal Perera',   '199012345V', '0771234567', FALSE),
('C-002', 'Kamal Silva',    '198556789V', '0712345678', TRUE),
('C-003', 'Sunil Fernando', '199245678V', '0759876543', FALSE);

-- ---------- Rentals ----------
DROP TABLE IF EXISTS rentals;
CREATE TABLE rentals (
    id          INT AUTO_INCREMENT PRIMARY KEY,
    rental_code VARCHAR(20)  NOT NULL UNIQUE,
    customer_id INT NOT NULL,
    tool_id     INT NOT NULL,
    rent_date   DATE NOT NULL,
    due_date    DATE NOT NULL,
    return_date DATE NULL,
    deposit_paid DECIMAL(10,2) NOT NULL DEFAULT 0,
    total_amount DECIMAL(10,2) NOT NULL DEFAULT 0,
    status      ENUM('Active', 'Returned', 'Overdue') NOT NULL DEFAULT 'Active',
    FOREIGN KEY (customer_id) REFERENCES customers(id),
    FOREIGN KEY (tool_id) REFERENCES tools(id)
);

INSERT INTO rentals (rental_code, customer_id, tool_id, rent_date, due_date, return_date, deposit_paid, total_amount, status) VALUES
('R-1001', 1, 1, '2026-09-27', '2026-09-30', NULL,       5000.00, 2400.00, 'Active'),
('R-1002', 2, 2, '2026-09-20', '2026-09-25', NULL,      15000.00, 7500.00, 'Overdue'),
('R-1003', 3, 4, '2026-09-28', '2026-10-02', NULL,       3000.00, 1600.00, 'Active'),
('R-1004', 1, 6, '2026-09-15', '2026-09-20', '2026-09-19', 8000.00, 6000.00, 'Returned');

-- ---------- Settings ----------
DROP TABLE IF EXISTS settings;
CREATE TABLE settings (
    `key`   VARCHAR(50) PRIMARY KEY,
    `value` VARCHAR(255) NOT NULL
);

INSERT INTO settings (`key`, `value`) VALUES
('late_fee_per_day', '200'),
('currency', 'LKR'),
('company_name', 'Rent A Tool'),
('backup_path', 'C:\\RentATool\\Backups');