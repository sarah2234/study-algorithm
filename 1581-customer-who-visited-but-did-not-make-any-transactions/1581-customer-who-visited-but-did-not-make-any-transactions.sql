# Write your MySQL query statement below
#SELECT v.customer_id, COUNT(v.visit_id) as count_no_trans
#FROM Visits v LEFT JOIN Transactions t ON v.visit_id =  t.visit_id
#WHERE transaction_id IS NULL
#GROUP BY customer_id;

#SELECT customer_id, COUNT(visit_id) as count_no_trans
#FROM Visits
#WHERE visit_id NOT IN (
#    SELECT visit_id 
#    FROM Transactions
#)
#GROUP BY customer_id

SELECT customer_id, COUNT(visit_id) as count_no_trans
FROM Visits
WHERE NOT EXISTS (
    SELECT visit_id
    FROM Transactions
    WHERE Visits.visit_id = Transactions.visit_id
)
GROUP BY customer_id