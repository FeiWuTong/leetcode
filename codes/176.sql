/*
 * Approach: MySQL
 * Time complexity: -   || 79.56% (193 ms)
 * Space complexity: -  || 100.00%
 */
# Write your MySQL query statement below
SELECT (
    SELECT DISTINCT Salary
    FROM Employee
    ORDER BY Salary DESC
    LIMIT 1
    OFFSET 1
)
AS SecondHighestSalary;

# or 7.54% (608 ms)
SELECT max(Salary) AS SecondHighestSalary
FROM Employee
WHERE Salary not in (
    SELECT max(Salary)
    FROM Employee 
);