/*
 * Approach: MySQL
 * Time complexity: -   || 84.97% (417 ms)
 * Space complexity: -  || 100.00%
 */
# Write your MySQL query statement below
SELECT DISTINCT l1.Num AS ConsecutiveNums FROM Logs l1, Logs l2, Logs l3
WHERE l1.Id=l2.Id-1 AND l2.Id=l3.Id-1
AND l1.Num = l2.Num AND l2.Num = l3.Num

# 22.98% (927 ms)
SELECT DISTINCT Num AS ConsecutiveNums FROM Logs
WHERE (Id + 1, Num) IN
(SELECT * FROM Logs) AND (Id + 2, Num) in (SELECT * FROM Logs)