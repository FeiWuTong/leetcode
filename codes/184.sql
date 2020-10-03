/*
 * Approach: MySQL
 * Time complexity: -   || 20.57% (1230 ms)
 * Space complexity: -  || 100.00%
 */
# Write your MySQL query statement below
SELECT D.Name AS Department, A.Name AS Employee, A.Salary
FROM Employee A, Department D
WHERE A.DepartmentId = D.Id AND NOT EXISTS (
    SELECT * FROM Employee B
    WHERE B.Salary > A.Salary AND B.DepartmentId = A.DepartmentId
)

# 59.84% (656 ms)
SELECT D.Name AS Department, E.Name AS Employee, E.Salary
FROM Employee E, Department D, (
    SELECT DepartmentId, max(Salary) AS m FROM Employee
    GROUP BY DepartmentId
    ) T
WHERE E.DepartmentId = D.Id AND E.Salary = T.m AND E.DepartmentId = T.DepartmentId