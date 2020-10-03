/*
 * Approach: MySQL
 * Time complexity: -   || 67.59% (437 ms)
 * Space complexity: -  || 100.00%
 */
# Write your MySQL query statement below
SELECT S.Score, COUNT(S2.Score) AS "Rank" FROM Scores S,
(SELECT DISTINCT Score FROM Scores) S2
WHERE S.Score<=S2.Score
GROUP BY S.Id 
ORDER BY S.Score DESC;

# Or use variables 15.72% (971 ms)
SELECT Score, convert(R1, SIGNED) AS "Rank" FROM
    (SELECT Score, @rank:=CASE WHEN Score=@previous THEN @rank ELSE @rank+1 END AS R1, @previous:=Score FROM Scores,
        (SELECT @previous:=-1, @rank:=0) AS initial
    ORDER BY Score DESC) A;