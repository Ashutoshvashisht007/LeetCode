# Write your MySQL query statement below
Select distinct(num) as ConsecutiveNums from Logs where (id + 1,num) in (Select * from Logs) and (id + 2,num) in (Select * from Logs);