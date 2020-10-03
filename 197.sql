/*
 * Approach: MySQL
 * Time complexity: -   || 29.66% (738 ms)
 * Space complexity: -  || 100.00%
 */
# Write your MySQL query statement below
SELECT w1.Id FROM Weather w1, Weather w2
WHERE w1.Temperature > w2.Temperature AND TO_DAYS(w1.DATE) - TO_DAYS(w2.DATE) = 1