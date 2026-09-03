SELECT 
    DATE_FORMAT(created_at, '%Y-%m-%d %H:00:00') AS log_hour,
    COUNT(*) AS total_errors
FROM system_logs
WHERE status_code >= 400 
  AND created_at >= CURDATE()
GROUP BY log_hour
ORDER BY log_hour ASC;
