# Write your MySQL query statement below

select score as 'score', 
dense_rank() over(order by score desc) as 'rank'
from scores;