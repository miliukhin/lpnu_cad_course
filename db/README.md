установити марію так!
```
sudo mariadb-install-db --user=mysql --basedir=/usr --datadir=/var/lib/mysql
```

кортеж=стрічка (рядок відношення таблиці)

домен=набір допустимих значень атрибутів

реляційна база

1. дані як сукупність відношень
2. відношення має бути чітко зображене в таблиці
3. рядки містять дані про екземпляри об'єкта
4. Стовпці повинні містити дані про атрибутисутності.
5. клітинки таблиці повинні мати одне значеня
6. кожному стовпцю варто надати унікальне ім'я
7. рядки не повторюються

## ШО ТАКЕ ЦІЛІСНІСТЬ

1. Відсутність кортежів-дублікатів
2. Атомарність значень атрибутів (не повторюютться структури даних)
3. Довільність порядку кортежів відношення
4. Унікальність імен атрибутів відношення

### Ключі

1. Потенційні
	- первинні
	- альтернативні (вторинні, унікальні) --- де взагалі?
2. Зовнішні

ціла сутність
у базовій таблиці жоден первинний ключ не 0, тобто мусить бути

### як зберегти цілісність

1. заборона
2. каскадні зміни
3. присвоєння NULL


1:1 для частовикористовуваних таблиць?

рекурсивний зв'язок
потенційний та зовнішній ключі належать
одній табиці

цілісність послинань
: фореігн кеу

## Підзапити

некорелюючі
: виконуються один раз

корелюючі
: мають псевдоніми для таблиць
шоб юзати ту саму зовні і всередині

> [correlated subquery:] In the above nested query the inner query has to be re-executed for each employee. (A sufficiently smart implementation may cache the inner query's result on a department-by-department basis, but even in the best case the inner query must be executed once per department.)

де фільтр за групами а де за даними
where herring

x = ALL (1,2)
x <> ALL (1,2)

підзапити в INSERT

insert into orders (product_id, created_at, product_count, price) <++>

case

partition працює
тільки БЕЗ прімару кеу


об'єднання таблиць (join)

оператор union
intersect просто замінити підзапитом

```
MariaDB [test]> select lname, mname from employee where salary >= (select avg(salary) from employee) order by id, lname ;
+----------+--------+
| lname    | mname  |
+----------+--------+
| Young    | Eric   |
| Anderson | Alfred |
| King     | Johann |
| Wright   | Fmeow  |
+----------+--------+
4 rows in set (0.001 sec)
```

## вибрані функції

скалярні
: повертають 1 значення обчислене з простих аргумнетів

групування
:  повертають 1 значення для набору аргументів запиту

RowSet
: мяу побавитесь

lower() upper()
: AAAAA -> aaaaa

concat()

left() right()

```sql
select concat(left(first_name,1), ". ', last_name) as Fname,
	left(account_sum,4) as Sum,
	first_name
from customer;
```

trim, [lr]trim

replace(a,b,c)
substring(text, start, n)
space(n)
reverse()
instr(a,b)

одиничка це неділя

datediff()

acsii() код символа
