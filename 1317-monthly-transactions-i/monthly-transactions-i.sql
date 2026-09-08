# Write your MySQL query statement below
select date_format(trans_date,'%Y-%m') as month,
country,
count(*) as trans_count,
sum(state='approved') as approved_count,
sum(amount) as trans_total_amount,
SUM(CASE WHEN state = 'approved' THEN amount ELSE 0 END) AS approved_total_amount
from transactions
GROUP BY month, country;