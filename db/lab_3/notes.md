```
CREATE DATABASE [IF NOT EXISTS] ім’я_бази_даних.
```

Друга форма `CREATE DATABASE IF NOT EXISTS ім’я_бази_даних`
намагається створити базу даних, якщо на сервері відсутня бд з таким ім'ям.

```
USE productsdb;
```

Видалення бази даних – `DROP DATABASE (або SCHEMA)`

`DROP DATABASE [IF EXISTS] імя_бази_даних;`

```sh
create table institute.student(
student_id int primary key,
surname varchar(40),
name_ varchar(30),
birthday date,
stipend decimal,
kurs int,
group int);
```

## Зміна

```
alter table institute.student add column id2 int not null after student_id;
alter table institute.student add column id_final int (6);
alter table institute.student add column id1 int (8) first;
```

Модифікація типу стовпця можлива лише тоді, якщо він порожній. Якщо
стовпець заповнений, то його довжину не можна зменшувати. Під час зміни стовпця
спочатку вказують його попередню назву, а потім – нову назву.

```
alter table institute.student change id2 id3 varchar(8) not null;
alter table institute.student change id3 id3 varchar(20);
```

Для видалення стовпця використовують умову DROP:

```
alter table institute.student drop column id2;
```

truncate
: removes all the records in the database table

name_ не просто так,
бо name зарезервоване

бажано таблиці в однині

```
select uuid();
```
