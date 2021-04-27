/*
 * Approach: MySQL
 * Time complexity: -   || 17.33%% (726 ms)
 * Space complexity: -  || 100.00%
 */
# Write your MySQL query statement below
SELECT Person.FirstName, Person.LastName, Address.City, Address.State
FROM Person
LEFT JOIN Address
ON Person.PersonId = Address.PersonId;