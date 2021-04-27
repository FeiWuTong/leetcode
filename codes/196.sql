/*
 * Approach: MySQL
 * Time complexity: -   || 12.27% (2672 ms)
 * Space complexity: -  || 100.00%
 */
# Write your MySQL query statement below
DELETE p1 FROM Person p1, Person p2
WHERE p1.Email = p2.Email AND p1.Id > p2.Id

# or 43.87% (1948 ms)
DELETE FROM Person
WHERE Id not in (
    SELECT t.Id From (
        SELECT min(Id) AS Id FROM Person
        GROUP BY Email
    ) t
)