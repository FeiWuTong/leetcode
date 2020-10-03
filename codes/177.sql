/*
 * Approach: MySQL
 * Time complexity: -   || 65.14% (350 ms)
 * Space complexity: -  || 100.00%
 */
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE M INT;
  SET M=N-1;
  RETURN (
      # Write your MySQL query statement below.
      SELECT (
          SELECT DISTINCT Salary
          FROM Employee
          ORDER BY Salary DESC
          LIMIT 1
          OFFSET M
      )
  );
END