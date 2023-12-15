drop database productdb;
create schema productdb;
use productdb;

create table product(
	id int auto_increment primary key,
	product_name varchar(30) not null,
	manufacturer varchar(30) not null,
	product_count int default 0,
	price decimal not null
);

insert into product (product_name, manufacturer, product_count, price) values
('iphone X', 'Apple', 2, 76000),
('iphone 8', 'Apple', 2, 51000),
('iphone 7', 'Apple', 5, 42000),
('Galaxy 59', 'Samsung', 2, 56000),
('Galaxy S8', 'Samsung', 1, 46000),
('Honor 10', 'Huawei', 2, 26000),
('Nokia 8', 'HMD Global', 6, 38000),
('iphone X1', 'Apple', 7, 56000),
('iphone 81', 'Apple', 7, 31000),
('iphone 71', 'Apple', 7, 22000),
('Galaxy 591', 'Samsung', 7, 36000),
('Galaxy S81', 'Samsung', 6, 26000),
('Honor 101', 'Huawei', 7, 16000),
('Nokia 81', 'HMD Global', 11, 18000),
('iphone x2', 'Apple', 9, 46000),
('iphone 82', 'Apple', 9, 21000),
('iphone 72', 'Apple', 12, 12000),
('Galaxy 592', 'Samsung', 9, 26000),
('Galaxy S82', 'Samsung', 8, 16000),
('Honor 182', 'Huawei', 9, 12000),
('Nokia 82', 'HMD Global', 13, 18000),
 ('iphone x3', 'Apple', 12, 78000),
 ('iphone 83', 'Apple', 12, 53000),
 ('iphone 73', 'Apple', 15, 46000),
 ('Galaxy S93', 'Samsung', 12, 58000),
 ('Galaxy 583', 'Samsung', 11, 48000),
 ('Honor 103', 'Huawei', 12, 28000),
('Nokia 83', 'HMD Global', 16, 40000);

/*
select * from product where manufacturer='Samsung' and price < 50000;

explain select * from product where manufacturer='Samsung' and price < 50000;

alter table product add index manufact_price (manufacturer, price);

explain select * from product where manufacturer='Samsung' and price < 50000;
*/
