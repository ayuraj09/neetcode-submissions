-- Write your query below
select  c.name from customers c left join orders o on o.customer_id = c.id where o.customer_id is null