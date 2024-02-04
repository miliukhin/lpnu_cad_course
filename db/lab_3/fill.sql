-- 1. Внесення імені, по батькові та прізвища в таблицю `buyer`

INSERT INTO `buyer` (`fname`, `mname`, `lname`)
VALUES
  ('John', 'John', 'Doe'),
  ('Jane', 'Dominique', 'Smith'),
  ('Robert', 'Charles', 'Johnson'),
  ('Sarah', 'Donald', 'Duck'),
  ('Michael', 'Fred', 'Brown'),
  ('Emily', 'Michael', 'Jones'),
  ('William', 'Gregory', 'Davis'),
  ('Olivia', 'Howard', 'Miller'),
  ('James', 'Ivan', 'Wilson'),
  ('Ava', 'George', 'Moore');

-- 2. Внесення імені, по батькові, прізвища, зарплати, посади та ID в таблицю `employee`

INSERT INTO `employee` (`fname`, `mname`, `lname`, `salary`, `position`, `id`)
VALUES
  ('David', 'Alfred', 'Anderson', 60000.00, 'manager', 1102),
  ('Linda', 'Bob', 'Clark', 55000.00, 'supervisor', 2101),
  ('Richard', 'Charles', 'Hall', 50000.00, 'salesperson', 1001),
  ('Mary', 'Donald', 'Garcia', 45000.00, 'salesperson', 1020),
  ('Daniel', 'Eric', 'Young', 70000.00, 'salesperson', 0230),
  ('Susan', 'Fmeow', 'Wright', 60000.00, 'salesperson', 1234),
  ('George', 'George', 'Harris', 55000.00, 'salesperson', 4321),
  ('Karen', 'Heeeeeeeee', 'Lee', 50000.00, 'salesperson', 9999),
  ('Edward', 'Joseph', 'Turner', 45000.00, 'salesperson', 0000),
  ('Helen', 'Johann', 'King', 70000.00, 'technician', 1111);


-- 3. Внесення адреси, номера телефону й назви в таблицю `manufacturer`

INSERT INTO `manufacturer` (`address_code`, `phone`, `name`)
VALUES
  (12345, 0952341234, 'GuitarCo'),
  (54321, 0683245678, 'MusicMakers'),
  (98765, 0982349876, 'SoundWave'),
  (12312, 0952387645, 'ibanjek'),
  (56789, 0952423345, 'jackdaughter'),
  (43210, 0982346789, 'Kurt'),
  (24680, 0953433421, 'Chibson'),
  (13579, 0982435342, 'bender'),
  (86420, 0953448769, 'MusicMagic'),
  (97531, 0952431122, 'NotePerfect');

-- 4. Внесення назв матеріалів у таблицю `material`

INSERT INTO `material` (`name`)
VALUES
  ('Oak'),
  ('Acacia'),
  ('Mahagoni'),
  ('Rosewood'),
  ('Maple'),
  ('Plastic'),
  ('Steel'),
  ('Brass'),
  ('Copper'),
  ('Bronze'),
  ('Fiberboard'),
  ('Carbon Fiber');

-- 5. Внесення кількості, ціни, назви, ID виробника та товару в таблицю `product`

INSERT INTO `product` (`quantity`, `price`, `name`, `id_manufacturer`, `id`)
VALUES
  (100, 599.99, '"GAGA" Electric Guitar', 5, 1001),
  (50, 799.99, '"Malyatko" Electric Guitar', 4, 1002),
  (75, 299.99, '"Spine" Double-Neck Acoustic Guitar', 7, 1003),
  (20, 129.99, '"Shredder" Electric Guitar', 8, 1004),
  (45, 749.99, 'Ibanjek G1958 Electric Guitar', 4, 1005),

  (45, 749.99, 'Ibanjek G6958 Electric Guitar', 4, 1006),
  (45, 749.99, 'Ibanjek G2958 Electric Guitar', 4, 1007),
  (45, 749.99, 'Ibanjek G3958 Electric Guitar', 4, 1008),
  (45, 749.99, 'Ibanjek G4958 Electric Guitar', 4, 1009),
  (45, 749.99, 'Ibanjek G5958 Electric Guitar', 4, 1010),

  (30, 199.99, '"Shimamimu" Flute', 4, 6060),
  (40, 499.99, 'Cool Pick', 5, 9097),
  (60, 399.99, '"Jazzmaster" Pick', 6, 9093),
  (55, 899.99, 'funny-looking cello', 9, 3303),
  (25, 349.99, 'bow', 10, 9003),
  (25, 349.99, '"chipupino" violin', 9, 2001),
  (25, 349.99, '"bambino" violin', 9, 2002),
  (25, 349.99, '"cupipi" violin', 9, 2003),
  (25, 349.99, '"strtok" violin', 9, 2004),
  (25, 349.99, '"strcmp" violin', 9, 2005),
  (25, 349.99, '"strcat" violin', 9, 2006),
  (25, 349.99, '"DROP" violin', 9, 2007),
  (25, 349.99, '"SELECT" violin', 9, 2008),
  (25, 349.99, '"DELETE" violin', 9, 2009),
  (25, 349.99, '"ALTER" violin', 9, 2010);

-- 6. Внесення ID продукта, матеріалу, та назву частини, виробленої з цього матеріалу в таблицю `product_has_material`
INSERT INTO `product_has_material` (`id_product`, `id_material`, `part_name`)
VALUES
  (1001, 1, 'fretboard'),
  (1001, 2, 'body'),
  (1001, 3, 'neck'),
  (1002, 2, 'fretboard'),
  (1002, 1, 'body'),
  (1002, 5, 'neck'),
  (1003, 4, 'fretboard'),
  (1003, 1, 'body'),
  (1003, 5, 'neck'),
  (1004, 4, 'fretboard'),
  (1004, 4, 'body'),
  (1004, 4, 'neck');

-- 7. Внесення смичкових інструментів у таблицю `bowed`
INSERT INTO `bowed` (`size`, `id`, `id_product`)
VALUES
  (4.2, 3302, 2001),
  (4.5, 6502, 2002),
  (4.3, 1102, 2003),
  (4.7, 1132, 2004),
  (4.0, 1042, 2005),
  (4.0, 1043, 2006),
  (4.0, 1044, 2007),
  (4.0, 1016, 2008),
  (4.0, 1046, 2010),
  (4.9, 1002, 2009);

-- 8. Внесення гітар у таблицю `guitar`
INSERT INTO `guitar` (`scaled_length`, `length`, `width`, `strings`, `frets`, `id_product`, `id`)
VALUES
  (25.5, 41, 14, 6, 22, 1001, 890891),
  (24.75, 39, 13, 6, 24, 1002, 890892),
  (26.0, 42, 15, 6, 22, 1003, 890893),
  (25.0, 40, 14, 6, 21, 1004, 890894),
  (25.5, 41, 14, 6, 24, 1005, 890895),
  (22.5, 36, 11, 5, 20, 1006, 890896),
  (23.0, 37, 12, 6, 22, 1007, 890897),
  (24.5, 39, 14, 6, 20, 1008, 890898),
  (25.0, 40, 15, 7, 22, 1009, 890899),
  (24.0, 38, 13, 6, 21, 1010, 890900);

-- 9. Внесення дати, ID покупця та продавця в таблицю `order_sheet`
INSERT INTO `order_sheet` (`date`, `id_buyer`, `id_seller`)
VALUES
  ('2023-10-13 10:00:00', 1, 2101),
  ('2023-10-13 11:00:00', 2, 2101),
  ('2023-10-13 12:00:00', 3, 1001),
  ('2023-10-13 13:00:00', 4, 1020),
  ('2023-10-13 14:00:00', 5, 0230),
  ('2023-10-13 15:00:00', 6, 1234),
  ('2023-10-13 16:00:00', 7, 4321),
  ('2023-10-13 17:00:00', 8, 9999),
  ('2023-10-13 18:00:00', 9, 0000),
  ('2023-10-13 19:00:00', 10, 0000);

-- 10. Внесення деталей замовлення в таблицю `order_details`
INSERT INTO `order_details` (`quantity_of_goods`, `id_order`, `id_product`)
VALUES
  (5, 1, 1001),
  (3, 1, 2001),
  (4, 2, 1002),
  (1, 2, 1003),
  (6, 3, 1004),
  (7, 3, 1005),
  (1, 4, 2001),
  (1, 5, 2002),
  (3, 6, 1001),
  (1, 7, 1007);
