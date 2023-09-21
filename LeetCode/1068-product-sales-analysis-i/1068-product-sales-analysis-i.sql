# Write your MySQL query statement below
SELECT DISTINCT p.product_name, s.year, s.price
FROM Sales s, Product p
WHERE s.product_id = p.product_id;