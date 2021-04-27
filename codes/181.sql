/*
 * Approach: MySQL
 * Time complexity: -   || 21.98% (781 ms)
 * Space complexity: -  || 100.00%
 */
# Write your MySQL query statement below
SELECT E1.Name AS Employee FROM Employee E1, Employee E2
WHERE E1.ManagerId = E2.Id AND E1.Salary > E2.Salary;