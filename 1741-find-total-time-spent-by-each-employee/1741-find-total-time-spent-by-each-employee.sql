# Write your MySQL query statement below
select event_day AS day,emp_id, SUM(out_time-in_time) AS total_time from Employees GROUP BY emp_id, day;