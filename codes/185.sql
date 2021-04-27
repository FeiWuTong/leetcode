/*
 * Approach: MySQL
 * Time complexity: -   || 7.37% (2422 ms)
 * Space complexity: -  || 100.00%
 */
# Write your MySQL query statement below
SELECT D.Name AS Department, A.Name AS Employee, A.Salary
FROM Employee A, Department D
WHERE A.DepartmentId = D.Id AND 3 > (
    SELECT count(DISTINCT Salary) FROM Employee
    WHERE DepartmentId = A.DepartmentId AND Salary > A.Salary
)
# 37.20% (1304 ms)
SELECT D.Name AS Department, A.Name AS Employee, A.Salary
FROM Employee A JOIN Department D ON A.DepartmentId = D.Id
WHERE 3 > (
     SELECT count(DISTINCT Salary) FROM Employee B
     WHERE B.DepartmentId = A.DepartmentId AND B.Salary > A.Salary
)