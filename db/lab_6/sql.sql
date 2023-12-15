----1----
set global event_scheduler = on;

drop table messages;
create table messages (
    id int primary key auto_increment,
    message varchar(255) not null
);

create event insert_message_event
on schedule at current_timestamp /*+ interval 1 second*/
do
    insert into messages (message) values ('Планова інсерція');


select * from messages;

show events from railway;

---

create event preserved_onetime
on schedule at current_timestamp + interval 10 second
on completion preserve
do
    insert into messages (message) values ('иьиьиьи');

select * from messages;
show events from railway;

---

create event regular_event
on schedule
every 10 second
starts current_timestamp
ends current_timestamp + interval 1 minute
do
	insert into messages (message) values ('Useless info');

select * from messages;
show events from test;

--- no tren <++>

create event one_time_event
on schedule at current_timestamp + interval 1 second
do
    insert into sales_reports (report_number, creation_date, products_sold, total_quantity_sold, total_revenue, employee_id, order_id)
    values (11, CURDatE(), 50, 200, 500, 3, 6);

create event recurring_event
on schedule every 2 second
starts current_timestamp
ends current_timestamp + interval 10 second
do
    update products set quantity_on_hand = quantity_on_hand - 5 where id = 3;

create event cyclic_event
on schedule
every 1 second
starts current_timestamp
ends current_timestamp + interval 1 hour
on completion Preserve
do
    delete from orders where status = 'Відмінено' and order_date < CURDatE();

---


DELIMITER //

create trigger before_insert_customer
before insert on pharmacy.customers
for each row
begin
    set new.status = 'Відправлено';
end//

create trigger before_insert_product
before insert on pharmacy.products
for each row
begin
    if new.quantity_on_hand is null then
        set new.quantity_on_hand = 0;
    end if;
    if new.price is null then
        set new.price = 0;
    end if;
end//

DELIMITER ;

INSERT INTO pharmacy.customers (full_name, phone_number) VALUES ('Іванов Бан Репер', '123-456-7890');

INSERT INTO pharmacy.products (name_, manufacturer, product_type, quantity_on_hand, price) VALUES ('Вітамін C', 'ABC Pharma', 'Таблетки', NULL, 100);

SELECT * FROM pharmacy.customers;
SELECT * FROM pharmacy.products;

----2-----
drop database tryger_demo;
create schema tryger_demo;

use tryger_demo;

create table account (act_num int, amount decimal(10,2));

create trigger ins_sum before insert on account
	for each row set @sum = @sum + new.amount;

set @sum = 0;
insert into account values
(137,14.98), (141, 1937.50), (97, -100.00);
select @sum as 'Total amount inserted';

create trigger ins_transaction before insert on account
for each row precedes ins_sum
set @deposits = @deposits + if(new.amount>0, new.amount, 0),
@withdrawals = @withdrawals + if(new.amount<0, -new.amount, 0);

set @deposits = 0;
set @withdrawals = 0;

select @withdrawals as 'withdrawals', @deposits as 'deposits';

delimiter //
create trigger upd_check before update on account
for each row
begin
	if new.amount < 0 then
    set new.amount =  0;
    elseif new.amount > 100 then
    set new.amount = 100;
    end if;
end;//
delimiter ;

update account set amount=-10 where act_num = 97;

--- <++>

DELIMITER //

create trigger before_insert_customer
before insert on pharmacy.customers
for each row
begin
    set new.status = 'Відправлено';
end//

create trigger before_insert_product
before insert on pharmacy.products
for each row
begin
    if new.quantity_on_hand is null then
        set new.quantity_on_hand = 0;
    end if;
    if new.price is null then
        set new.price = 0;
    end if;
end//

DELIMITER ;

----3-----
drop database company;

create schema company;

use company;
drop procedure  my_proc_select;
drop procedure my_proc_out;

create table employees (
    id int auto_increment primary key,
    job_id varchar(15) not null,
    job_title varchar(45) not null ,
    min_salary int not null,
    max_salary int not null
);

INSERT INTO employees (job_id, job_title, min_salary, max_salary)
VALUES
('JOB001', 'Менеджер', 30000, 60000),
('JOB002', 'Програміст', 35000, 70000),
('JOB003', 'Дизайнер', 28000, 55000),
('JOB004', 'Тестувальник', 25000, 50000),
('JOB005', 'Аналітик', 32000, 65000),
('JOB006', 'Адміністратор', 28000, 55000),
('JOB007', 'Маркетолог', 30000, 60000),
('JOB008', 'Фінансист', 35000, 70000),
('JOB009', 'Копірайтер', 26000, 52000),
('JOB010', 'Архітектор', 38000, 76000);

DELIMITER //

create procedure my_proc_select()
begin
    select * from employees;
end//

call my_proc_select;
DELIMITER ;

DELIMITER //
create procedure my_proc_out(out highest_salary int)
begin
select max(max_salary) into highest_salary from employees;
end//
DELIMITER ;
call my_proc_out(@m);
select @m;
DELIMITER //
DELIMITER //

create procedure my_proc_case(inout no_employees int, in salary int)
begin
    case
    when (salary > 10000) then
        select count(job_id) into no_employees from employees where min_salary > 10000;
    when (salary < 10000) then
        select count(job_id) into no_employees from employees where min_salary < 10000;
    else
        select count(job_id) into no_employees from employees where min_salary = 10000;
    end case;
end//

DELIMITER ;


drop database company;

create schema company;

use company;
drop procedure  my_proc_select;
drop procedure my_proc_out;
create table employees (
    id int auto_increment primary key,
    job_id varchar(15) not null,
    job_title varchar(45) not null ,
    min_salary int not null,
    max_salary int not null
);

INSERT INTO employees (job_id, job_title, min_salary, max_salary)
VALUES
('JOB001', 'Менеджер', 30000, 60000),
('JOB002', 'Програміст', 35000, 70000),
('JOB003', 'Дизайнер', 28000, 55000),
('JOB004', 'Тестувальник', 25000, 50000),
('JOB005', 'Аналітик', 32000, 65000),
('JOB006', 'Адміністратор', 28000, 55000),
('JOB007', 'Маркетолог', 30000, 60000),
('JOB008', 'Фінансист', 35000, 70000),
('JOB009', 'Копірайтер', 26000, 52000),
('JOB010', 'Архітектор', 38000, 76000);

DELIMITER //

create procedure my_proc_select()
begin
    select * from employees;
end//

call my_proc_select;
DELIMITER ;

DELIMITER //
create procedure my_proc_out(out highest_salary int)
begin
select max(max_salary) into highest_salary from employees;
end//
DELIMITER ;
call my_proc_out(@m);
select @m;

DELIMITER //

create procedure my_proc_case(inout no_employees int, in salary int)
begin
    case
    when (salary > 10000) then
        select count(job_id) into no_employees from employees where min_salary > 10000;
    when (salary < 10000) then
        select count(job_id) into no_employees from employees where min_salary < 10000;
    else
        select count(job_id) into no_employees from employees where min_salary = 10000;
    end case;
end//

DELIMITER ;


call my_proc_case(@c, 10001);
select @c;
call my_proc_case(@c, 9999);
select @c;
call my_proc_case(@c, 10000);
select @c;

DELIMITER //
create procedure my_proc_select2(in title varchar(45), out salary int)
begin
select min_salary into salary from employees where job_title = title;
end //
DELIMITER ;

call my_proc_select2('Менеджер', @s);
select @s;


DELIMITER //
create function hello (s char(20))
returns char(50)
deterministic
begin
return concat('Hello,   ', s,'!');
end //


DELIMITER ;

set @title = (select job_title from employees where id = 5);
set @text_hello = hello(@title);

select @text_hello;
