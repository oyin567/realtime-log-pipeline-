CREATE DATABASE IF NOT EXISTS log_analytics;
USE log_analytics;

CREATE TABLE IF NOT EXISTS system_logs (
    id INT AUTO_INCREMENT PRIMARY KEY,
    ip_address VARCHAR(45) NOT NULL,
    status_code INT NOT NULL,
    endpoint VARCHAR(255) NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

INSERT INTO system_logs (ip_address, status_code, endpoint) 
VALUES 
('127.0.0.1', 200, '/api/health'),
('192.168.0.1', 500, '/api/auth');

SELECT status_code, COUNT(*) AS occurrences 
FROM system_logs 
GROUP BY status_code;
