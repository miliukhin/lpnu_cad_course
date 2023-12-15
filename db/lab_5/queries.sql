describe bowed

select buyer.lname as buyer, employee.id as seller, order_sheet.id
from order_sheet
join buyer on order_sheet.id_buyer = buyer.id
join employee on order_sheet.id_seller = employee.id

select fname, mname, lname,
CASE
	WHEN salary < (select avg(salary) from employee)
		then fname
	else 'big'
end as salary
from employee

select mname from buyer
EXCEPT select mname from employee;

/*
select mname from buyer
union select mname from employee;
*/

select mname from buyer
union select mname from employee;

select buyer.mname, employee.mname
from buyer
join employee on employee.mname = buyer.mname;
