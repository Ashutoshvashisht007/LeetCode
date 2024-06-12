# Write your MySQL query statement below
Select e.name as Employee from Employee e inner join Employee e1 on e.managerId = e1.id where e.salary > e1.salary 