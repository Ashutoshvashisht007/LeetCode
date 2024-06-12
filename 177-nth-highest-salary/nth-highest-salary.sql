CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
DECLARE M INT;
SET M = N - 1;
  RETURN (
      # Write your MySQL query statement below.
       Select Distinct salary from Employee order by salary desc limit 1 OFFSET M
  );
END