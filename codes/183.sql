/*
 * Approach: MySQL
 * Time complexity: -   || 65.63% (451 ms)
 * Space complexity: -  || 100.00%
 */
# Write your MySQL query statement below
SELECT Name As Customers FROM Customers
WHERE Id NOT IN (SELECT CustomerId FROM Orders)