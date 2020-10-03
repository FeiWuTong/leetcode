/*
 * Approach: MySQL
 * Time complexity: -   || 19.14% (781 ms)
 * Space complexity: -  || 100.00%
 */
# Write your MySQL query statement below
SELECT DISTINCT p1.Email FROM Person p1, Person p2
WHERE p1.Email = p2.Email AND p1.Id != p2.Id

# 13.29% (840 ms)
SELECT Email FROM Person
GROUP BY Email
HAVING count(*) > 1