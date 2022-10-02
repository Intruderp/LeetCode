# Write your MySQL query statement below

select name as customers 
from customers
where customers.id not in (
    select customerid from orders
);