---
pdf-engine: xelatex
lang: uk-UA
bibliography: "/home/sasha/Documents/uni/bibliography.bib"
header-includes:
- \input{$UNI/.templates/settings/preamble.tex}
- \input{$UNI/.templates/settings/minted_settings.tex}
- \renewcommand\Variant{6}
- \newcommand\Date{16.11.\the\year}
- \newcommand\Discipline{Організація баз даних та знань}
- \newcommand\Instructor{Головацький Р. І.}
- \newcommand\Type{\RGR}
- \newcommand\Number{}
- \newcommand\Topic{Магазин музичних інструментів}
- \usepackage{etoolbox}
- \newtoggle{Report}
- \togglefalse{Report}
- \newtoggle{ShowVar}
- \togglefalse{ShowVar}
- \renewcommand\Department{САПР}
- \newcommand\Class{студент групи \Group}
- \newcommand\Author{\Lname~\Initials}
- \newcommand\Position{асистент каф. САП}
nocite: '@mysql, @mariadb, @dbman, @denik, @dbrgr'
---

\input{$UNI/.templates/parts/titlepage.tex}

\tableofcontents

# Позначення

БД
: база даних

ПО
: предметна область

СКБД
: система керування базами даних

РГР
: розрахунково-графічна робота

# Вступ

Метою виконання розрахунково-графічної роботи (РГР) є закріплення та
поглиблення знань, отриманих під час вивчення курсу “Організація баз даних та
знань”, набуття практичних навичок та вмінь подальшого їх використання для
проектування баз даних (БД).

Основними завданнями розрахунково-графічної роботи є:

- узагальнення теоретичних знань, отриманих під час вивчення дисципліни
“Організація баз даних та знань”, за допомогою поглибленого вивчення додаткової
фахової літератури;
- набуття навичок практичного застосування теоретичних знань, проведення
дослідження й аналізу існуючих програмних систем та побудова інформаційної
системи предметної області;
- набуття практичних вмінь постановки інженерних задач, проектування
складних систем та їх реалізація; розроблення супровідної технічної документації до
виконаної роботи.

# 1. Побудова інфологічної та даталогічної моделей БД.

## Опис предметної області

Я обрав ПО "магазин музичних інструментів".
Потрібно відстежувати продажі та надавати
покупцям інформацію про товар, тому зберігати
треба:

- характеристики товару
- виробника
- покупця
- продавця
- інформацію про замовлення

#### Типові запити

- Скільки товару в наявності?
- Хто виробник?
- Скільки, коли, кому й чого продали?
- Які характеристики товару?
- Яка в якого працівника зарплата/успішність?
- Які товари частіше купують?

#### Базові сутності та зв'язки між ними

1. Виробник (Адреса, ідентифікатор, номер телефону)
2. Товар
3. Матеріал
4. Різні типи товарів.
5. Покупець (ID, ПІБ)
6. Продавець
7. Замовлення
8. Деталі замовлення.

Маємо 6 базових сутностей: *товар, виробник, працівник,
покупець, замовлення, деталі замовлення*. Далі можемо додавати
сутності для різних категорій товарів, наприклад,
гітари та смичкові, а також сутність матеріал, щоб
зручно зберігати матеріали, з яких виготовлені
інструменти **(разом 9)**. Таблиця нижче відображає їх характеристики
детальніше:

\csvautolongtable{/home/sasha/Documents/uni/db/lab_1/table.csv}

## Побудова ER-діаграми

Я використав `eralchemy` замість `ERDplus`,
бо ця програма:

1. Працює локально.
2. Компілює моделі з розмітки або готових баз.
3. тому не має важкого графічного інтерфейсу
4. Вільна.

Діаграму додаю.

# 2. Фізичне проектування БД засобами СКБД.

Коли я почав будувати фізичну модель бази даних,
то зрозумів, що багато що зробив неправильно на
початку (хоча чи це неправильно, чи, радше, неточно,
--- окреме питання). Тому фізична модель доволі
сильно відрізняється.

До розрахунково-графічної роботи додаю
дамп бази, такої, якою вона вийшла в результаті.
Також додаю фізичну модель.

# 3. Проектування БД предметної області засобами SQL.

## 3.1. Побудова запитів SQL.

### Завдання 1

#### 1. Вибрати всі поля з таблиці `product`.
Для цього використовую простий `select` із
замінним знаком `*`.

```sql
MariaDB [test]> select * from product;
+------+----------+--------+-------------------------------------+-----------------+
| id   | quantity | price  | name                                | id_manufacturer |
+------+----------+--------+-------------------------------------+-----------------+
| 1001 |      100 | 599.99 | "GAGA" Electric Guitar              |               5 |
| 1002 |       50 | 799.99 | "Malyatko" Electric Guitar          |               4 |
| 1003 |       75 | 299.99 | "Spine" Double-Neck Acoustic Guitar |               7 |
| 1004 |       20 | 129.99 | "Shredder" Electric Guitar          |               8 |
| 1005 |       45 | 749.99 | Ibanjek G1958 Electric Guitar       |               4 |
| 1006 |       45 | 749.99 | Ibanjek G6958 Electric Guitar       |               4 |
| 1007 |       45 | 749.99 | Ibanjek G2958 Electric Guitar       |               4 |
| 1008 |       45 | 749.99 | Ibanjek G3958 Electric Guitar       |               4 |
| 1009 |       45 | 749.99 | Ibanjek G4958 Electric Guitar       |               4 |
| 1010 |       45 | 749.99 | Ibanjek G5958 Electric Guitar       |               4 |
| 2001 |       25 | 349.99 | "chipupino" violin                  |               9 |
| 2002 |       25 | 349.99 | "bambino" violin                    |               9 |
| 2003 |       25 | 349.99 | "cupipi" violin                     |               9 |
| 2004 |       25 | 349.99 | "strtok" violin                     |               9 |
| 2005 |       25 | 349.99 | "strcmp" violin                     |               9 |
| 2006 |       25 | 349.99 | "strcat" violin                     |               9 |
| 2007 |       25 | 349.99 | "DROP" violin                       |               9 |
| 2008 |       25 | 349.99 | "SELECT" violin                     |               9 |
| 2009 |       25 | 349.99 | "DELETE" violin                     |               9 |
| 2010 |       25 | 349.99 | "ALTER" violin                      |               9 |
| 3303 |       55 | 899.99 | funny-looking cello                 |               9 |
| 6060 |       30 | 199.99 | "Shimamimu" Flute                   |               4 |
| 9003 |       25 | 349.99 | bow                                 |              10 |
| 9093 |       60 | 399.99 | "Jazzmaster" Pick                   |               6 |
| 9097 |       40 | 499.99 | Cool Pick                           |               5 |
+------+----------+--------+-------------------------------------+-----------------+
25 rows in set (0.001 sec)
```
Запит вибрав усі поля з таблиці `product`.

#### 2. Вибрати 5 рядків із таблиці `material`:

обмежую вивід за допомогою `limit` із заданим числом 5.
```sql
MariaDB [test]> select * from material limit 5;
+----+----------+
| id | name     |
+----+----------+
|  1 | Oak      |
|  2 | Acacia   |
|  3 | Mahagoni |
|  4 | Rosewood |
|  5 | Maple    |
+----+----------+
5 rows in set (0.001 sec)
```
Як бачимо, марія вивела тільки 5 рядків.

#### 3. Вибрати різні `id` виробника з таблиці `product`

Це можна зробити за допомогою оператора `distinct`:
```sql
MariaDB [test]> select distinct id_manufacturer from product
    -> ;
+-----------------+
| id_manufacturer |
+-----------------+
|               4 |
|               5 |
|               6 |
|               7 |
|               8 |
|               9 |
|              10 |
+-----------------+
7 rows in set (0.001 sec)
```
Сервер успішно обробив мій запит.

#### 4. Вибрати всіх працівників, у яких визначене середнє ім'я.

Для цього додаю до селекту умову `where mname is not null`:
```sql
MariaDB [test]> select * from employee where  mname is not null;
+------+---------+------------+----------+--------+-------------+
| id   | fname   | mname      | lname    | salary | position    |
+------+---------+------------+----------+--------+-------------+
|    0 | Edward  | Joseph     | Turner   |  45000 | salesperson |
|  230 | Daniel  | Eric       | Young    |  70000 | salesperson |
| 1001 | Richard | Charles    | Hall     |  50000 | salesperson |
| 1020 | Mary    | Donald     | Garcia   |  45000 | salesperson |
| 1102 | David   | Alfred     | Anderson |  60000 | manager     |
| 1111 | Helen   | Johann     | King     |  70000 | technician  |
| 1234 | Susan   | Fmeow      | Wright   |  60000 | salesperson |
| 2101 | Linda   | Bob        | Clark    |  55000 | supervisor  |
| 4321 | George  | George     | Harris   |  55000 | salesperson |
| 9999 | Karen   | Heeeeeeeee | Lee      |  50000 | salesperson |
+------+---------+------------+----------+--------+-------------+
10 rows in set (0.001 sec)
```
Працівників із нульовим середнім іменем не вивело.

#### 5. Вибрати лади з гітар та записати вивід у файл `frets_from_guitar`.

Для цього застосую конструкцію `into outfile <назва_файлу>`, запит виглядатиме так:
```sql
MariaDB [test]> select frets into outfile 'frets_from_guitar' from guitar
Query OK, 10 rows affected (0.001 sec)
```

Перевіряємо вміст утвореного файлу:
```sh
[penumbra test]# cat frets_from_guitar
22
24
22
21
24
20
22
20
22
21
```
Бачимо, що там дійсно записана кількість ладів кожної гітари.

### Завдання 2

#### 1. Вибрати всі поля з `manufacturer` та відсортувати їх за стовпцем `name`.

Скористаюсь оператором `order by`:
```sql
MariaDB [test]> select * from manufacturer order by name;
+----+--------------+-----------+--------------+
| id | address_code | phone     | name         |
+----+--------------+-----------+--------------+
|  8 |        13579 | 982435342 | bender       |
|  7 |        24680 | 953433421 | Chibson      |
|  1 |        12345 | 952341234 | GuitarCo     |
|  4 |        12312 | 952387645 | ibanjek      |
|  5 |        56789 | 952423345 | jackdaughter |
|  6 |        43210 | 982346789 | Kurt         |
|  9 |        86420 | 953448769 | MusicMagic   |
|  2 |        54321 | 683245678 | MusicMakers  |
| 10 |        97531 | 952431122 | NotePerfect  |
|  3 |        98765 | 982349876 | SoundWave    |
+----+--------------+-----------+--------------+
10 rows in set (0.001 sec)
```
Бачимо, що рядки відсортовані за стовпчиком `name` у порядку зростання (від літери з найменшим кодом до літери з найбільшим).

#### 2. Вибрати дату замовлення з `order_sheet` і відсортувати за `id` продавця в порядку спадання.
Для цього до `order by` додаю специфікатор `desc`,
що значить descending:

```sql
MariaDB [test]> select date from order_sheet order by id_seller desc;
+---------------------+
| date                |
+---------------------+
| 2023-10-13 17:00:00 |
| 2023-10-13 16:00:00 |
| 2023-10-13 10:00:00 |
| 2023-10-13 11:00:00 |
| 2023-10-13 15:00:00 |
| 2023-10-13 13:00:00 |
| 2023-10-13 12:00:00 |
| 2023-10-13 14:00:00 |
| 2023-10-13 18:00:00 |
| 2023-10-13 19:00:00 |
+---------------------+
10 rows in set (0.001 sec)
```
Успішно зроблено зручно.

#### 3. Вибрати назву частини інструмента, `id` матеріалу з `product_has_material` та відсортувати за `id_material`.

Для цього спочатку вкажу, що треба вибрати (`part_name`, `id_material`), а далі відсортую за допомогою
`order by`, оскільки в порядку зростання `id_material`, то `id_material asc`.
```sql
MariaDB [test]> select part_name, id_material
			from product_has_material
			order by id_material asc;
+-----------+-------------+
| part_name | id_material |
+-----------+-------------+
| fretboard |           1 |
| body      |           1 |
| body      |           1 |
| body      |           2 |
| fretboard |           2 |
| neck      |           3 |
| body      |           4 |
| fretboard |           4 |
| fretboard |           4 |
| neck      |           4 |
| neck      |           5 |
| neck      |           5 |
+-----------+-------------+
12 rows in set (0.001 sec)
```
Видно, що вивід відсортований за полем `id_material`, а це те, що нам потрібно.

### Завдання 3

#### 1. Вибрати всі значення з продуктів, де кількість або 25, або 30.

Для реалізації цього запиту
використовую `in` та надаю відповідно значення 25 і 30:
```sql
MariaDB [test]> select * from product where quantity in (25, 30);
+------+----------+--------+--------------------+-----------------+
| id   | quantity | price  | name               | id_manufacturer |
+------+----------+--------+--------------------+-----------------+
| 2001 |       25 | 349.99 | "chipupino" violin |               9 |
| 2002 |       25 | 349.99 | "bambino" violin   |               9 |
| 2003 |       25 | 349.99 | "cupipi" violin    |               9 |
| 2004 |       25 | 349.99 | "strtok" violin    |               9 |
| 2005 |       25 | 349.99 | "strcmp" violin    |               9 |
| 2006 |       25 | 349.99 | "strcat" violin    |               9 |
| 2007 |       25 | 349.99 | "DROP" violin      |               9 |
| 2008 |       25 | 349.99 | "SELECT" violin    |               9 |
| 2009 |       25 | 349.99 | "DELETE" violin    |               9 |
| 2010 |       25 | 349.99 | "ALTER" violin     |               9 |
| 6060 |       30 | 199.99 | "Shimamimu" Flute  |               4 |
| 9003 |       25 | 349.99 | bow                |              10 |
+------+----------+--------+--------------------+-----------------+
12 rows in set (0.001 sec)
```
Вибрало всі значення з продуктів, де кількість або 25, або 30.

#### 2. Вибрати назву та ціну з продуктів, де `id` від 2000 до 3000.

Я зроблю це, використавши
оператор `between`:
```sql
MariaDB [test]> select name, price from product where id between 2000 and 3000;
+--------------------+--------+
| name               | price  |
+--------------------+--------+
| "chipupino" violin | 349.99 |
| "bambino" violin   | 349.99 |
| "cupipi" violin    | 349.99 |
| "strtok" violin    | 349.99 |
| "strcmp" violin    | 349.99 |
| "strcat" violin    | 349.99 |
| "DROP" violin      | 349.99 |
| "SELECT" violin    | 349.99 |
| "DELETE" violin    | 349.99 |
| "ALTER" violin     | 349.99 |
+--------------------+--------+
10 rows in set (0.001 sec)
```
Вибрав назву та ціну з продуктів, де `id` від 2000 до 3000.

#### 3. Вивести покупців, у яких ім'я починається з `j` (`J`):

Для цього можна вжити чи регулярний вираз, чи суто sql-івський оператор
`like`, що я і зроблю:
```sql
MariaDB [test]> select * from buyer where fname like "j%";
+----+-------+-----------+--------+
| id | fname | mname     | lname  |
+----+-------+-----------+--------+
|  1 | John  | John      | Doe    |
|  2 | Jane  | Dominique | Smith  |
|  9 | James | Ivan      | Wilson |
+----+-------+-----------+--------+
3 rows in set (0.001 sec)
```
Бачимо, що фільтрування успішне.

#### 4. Вивести покупців, у яких в ім'ї присутня буква `m`, після якої йде `i`, `j` чи `m`.

Для цього вже однозначно легше та зручніше скористатися регулярним виразом,
оскільки в MariaDB вони реалізовані за допомогою оператора `regexp`, записуємо:
```sql
MariaDB [test]> select * from buyer where fname regexp "m[ijm]";
+----+---------+---------+-------+
| id | fname   | mname   | lname |
+----+---------+---------+-------+
|  5 | Michael | Fred    | Brown |
|  6 | Emily   | Michael | Jones |
+----+---------+---------+-------+
2 rows in set (0.001 sec)
```
Вивід відповідає вимогам.

#### 5. Вибрати продукти, в яких назва закінчується на `r`:

Для цього таким самим чином застосую вже інший регулярний вираз --- `r$`.
```sql
MariaDB [test]> select * from product where name regexp "r$";
+------+----------+--------+-------------------------------------+-----------------+
| id   | quantity | price  | name                                | id_manufacturer |
+------+----------+--------+-------------------------------------+-----------------+
| 1001 |      100 | 599.99 | "GAGA" Electric Guitar              |               5 |
| 1002 |       50 | 799.99 | "Malyatko" Electric Guitar          |               4 |
| 1003 |       75 | 299.99 | "Spine" Double-Neck Acoustic Guitar |               7 |
| 1004 |       20 | 129.99 | "Shredder" Electric Guitar          |               8 |
| 1005 |       45 | 749.99 | Ibanjek G1958 Electric Guitar       |               4 |
| 1006 |       45 | 749.99 | Ibanjek G6958 Electric Guitar       |               4 |
| 1007 |       45 | 749.99 | Ibanjek G2958 Electric Guitar       |               4 |
| 1008 |       45 | 749.99 | Ibanjek G3958 Electric Guitar       |               4 |
| 1009 |       45 | 749.99 | Ibanjek G4958 Electric Guitar       |               4 |
| 1010 |       45 | 749.99 | Ibanjek G5958 Electric Guitar       |               4 |
+------+----------+--------+-------------------------------------+-----------------+
10 rows in set (0.001 sec)
```
Відображаються тільки продукти з `r` у кінці назви, отже, запит успішний.

### Завдання 4

#### 1. Вивести середню ціну з продуктів:

використаю агрегатну функцію `avg`, надам їй параметр `price`:
```sql
MariaDB [test]> select avg(price) from product;
+--------------------+
| avg(price)         |
+--------------------+
| 487.18999145507814 |
+--------------------+
1 row in set (0.013 sec)
```
Вивело середню ціну продуктів.

#### 2. Вибрати продукти, в яких ціна в діапазоні `максимальна_ціна` --- `максимальна_ціна - 200`.

Для цього напишу вкладений запит, який вибирає максимальну ціну та віднімає від неї 200
за допомогою агрегатної функції max().
```sql
MariaDB [test]> select * from product where price >
			(select max(price)-200 from product);
+------+----------+--------+-------------------------------+-----------------+
| id   | quantity | price  | name                          | id_manufacturer |
+------+----------+--------+-------------------------------+-----------------+
| 1002 |       50 | 799.99 | "Malyatko" Electric Guitar    |               4 |
| 1005 |       45 | 749.99 | Ibanjek G1958 Electric Guitar |               4 |
| 1006 |       45 | 749.99 | Ibanjek G6958 Electric Guitar |               4 |
| 1007 |       45 | 749.99 | Ibanjek G2958 Electric Guitar |               4 |
| 1008 |       45 | 749.99 | Ibanjek G3958 Electric Guitar |               4 |
| 1009 |       45 | 749.99 | Ibanjek G4958 Electric Guitar |               4 |
| 1010 |       45 | 749.99 | Ibanjek G5958 Electric Guitar |               4 |
| 3303 |       55 | 899.99 | funny-looking cello           |               9 |
+------+----------+--------+-------------------------------+-----------------+
8 rows in set (0.000 sec)
```
Менше ніж 699.99 нічого не вивело, отже, все правильно.

#### 3. Вибрати мінімальне прізвище працівника, `id` якого менше за 100.

Пишу таке:
```sql
MariaDB [test]> select min(fname) from employee where id < 100;
+------------+
| min(fname) |
+------------+
| Edward     |
+------------+
1 row in set (0.001 sec)
```
У цьому SQL-запиті використовується оператор SELECT для вибору мінімального прізвища працівника, у якого id менше за 100. Агрегатна функція MIN використовується для знаходження найменшого значення у вказаному стовпці (fname). Результатом є прізвище працівника з найменшим значенням у вказаному діапазоні id.

#### 4. Вивести кількість покупців, у яких `id` більше за 5:

```sql
MariaDB [test]> select count(*) from buyer where id > 5;
+----------+
| count(*) |
+----------+
|        5 |
+----------+
1 row in set (0.001 sec)
```
У цьому SQL-запиті використовується оператор SELECT для підрахунку кількості покупців у таблиці buyer, у яких значення id перевищує 5.

#### 5. Вивести ціну всіх продуктів:

```sql
MariaDB [test]> select sum(price*quantity) from product;
+---------------------+
| sum(price*quantity) |
+---------------------+
|   523340.2412414551 |
+---------------------+
1 row in set (0.001 sec)
```
Оператор SELECT використовується для обчислення загальної ціни всіх продуктів у таблиці product. Функція SUM використовується для підрахунку суми цін, отриманих шляхом множення ціни на кількість. Результатом є загальна вартість всіх продуктів.

### Завдання 5

#### 1. Відобразити кількість різних видів товарів від кожного виробника.

Запит виглядає якось так:
```sql
MariaDB [test]> select id_manufacturer, count(*) as count
    -> from product
    -> group by id_manufacturer
    -> order by count;
+-----------------+-------+
| id_manufacturer | count |
+-----------------+-------+
|               6 |     1 |
|               7 |     1 |
|               8 |     1 |
|              10 |     1 |
|               5 |     2 |
|               4 |     8 |
|               9 |    11 |
+-----------------+-------+
7 rows in set (0.001 sec)
```
У цьому SQL-запиті використовується оператор SELECT для виведення кількості різних видів товарів (count) від кожного виробника (id_manufacturer). Для цього використовується функція COUNT, а також групування за id_manufacturer. Результат виводиться в порядку зростання кількості товарів.

#### 2. Вибрати загальну кількість товарів різних виробників та суму їх цін.

Ось така конструкція виведе те, що нам потрібно:
```sql
MariaDB [test]> select id_manufacturer, sum(price), sum(quantity)
    -> from product group by id_manufacturer;
+-----------------+--------------------+---------------+
| id_manufacturer | sum(price)         | sum(quantity) |
+-----------------+--------------------+---------------+
|               4 |  5499.919937133789 |           350 |
|               5 |   1099.97998046875 |           140 |
|               6 |   399.989990234375 |            60 |
|               7 |   299.989990234375 |            75 |
|               8 | 129.99000549316406 |            20 |
|               9 |  4399.889892578125 |           305 |
|              10 |   349.989990234375 |            25 |
+-----------------+--------------------+---------------+
7 rows in set (0.001 sec)
```
У цьому SQL-запиті використовується оператор SELECT для виведення загальної кількості товарів та суми їх цін (price) для кожного виробника (id_manufacturer). Для цього використовується функція SUM та групування за id_manufacturer. Результат включає загальну ціну та кількість товарів для кожного виробника.

#### 3. Вибрати `id` виробника, перше слово з назви та кількість видів товарів кожного виробника, кількість виробів якого перевищує 1:

Використовую такий хитрий запит:
\scriptsize
```sql
MariaDB [music_store]> select id_manufacturer, group_concat(SUBSTRING_INDEX( name, ' ', 1 )), count(*) as count from product group by id_manufacturer;
+-----------------+----------------------------------------------------------------------------------------------------------+-------+
| id_manufacturer | group_concat(SUBSTRING_INDEX( name, ' ', 1 ))                                                            | count |
+-----------------+----------------------------------------------------------------------------------------------------------+-------+
|               4 | "Malyatko",Ibanjek,Ibanjek,Ibanjek,Ibanjek,Ibanjek,Ibanjek,"Shimamimu"                                   |     8 |
|               5 | "GAGA",Cool                                                                                              |     2 |
|               6 | "Jazzmaster"                                                                                             |     1 |
|               7 | "Spine"                                                                                                  |     1 |
|               8 | "Shredder"                                                                                               |     1 |
|               9 | "chipupino","bambino","cupipi","strtok","strcmp","strcat","DROP","SELECT","DELETE","ALTER",funny-looking |    11 |
|              10 | bow                                                                                                      |     1 |
|              13 | table                                                                                                    |     1 |
+-----------------+----------------------------------------------------------------------------------------------------------+-------+
8 rows in set (0.001 sec)
```
\normalsize
Тут для вибору першого слова з назви викроистовується функція SUBSTRING_INDEX із параметрами `name, ' ', 1`,
а для вибору кількості --- `count(*)`. Усе групується за `id_manufacturer`.

### Завдання 6

#### 1. Створити таблицю замовлень за жовтень 2023 року.

Подання буде містити всю інформацію про замовлення з `order_sheet`, де
дата відповідає нашому критерію:
```sql
MariaDB [test]> create view orders_23_10 as select * from order_sheet where date regexp
    -> "2023-10";
Query OK, 0 rows affected (0.305 sec)
MariaDB [test]> show tables
    -> ;
+----------------------+
| Tables_in_test       |
+----------------------+
| bowed                |
| buyer                |
| employee             |
| guitar               |
| manufacturer         |
| material             |
| order_details        |
| order_sheet          |
| orders_23_10         |
| product              |
| product_has_material |
+----------------------+
11 rows in set (0.001 sec)
```
Подання створене й відображає те, що треба.

#### 2. Створити подання дат замовлень, ім'я покупця в яких містить `john`:

Для фільтруванння застосую `like`:
```sql
MariaDB [test]> create view john_order_dates as select id, date from order_sheet where
    -> id_buyer in (select id from buyer where fname like "john");
Query OK, 0 rows affected (0.062 sec)
MariaDB [test]> select * from john_order_dates;
+----+---------------------+
| id | date                |
+----+---------------------+
|  1 | 2023-10-13 10:00:00 |
+----+---------------------+
1 row in set (0.053 sec)
```
Видно, що `john`-и замовили тільки раз, 2023-10-13 о 10:00.

### Завдання 7

#### 1. Додаю користувача та надаю йому всі дозволи:

Для створення користувача вжиткую `create user`, задаю пароль за допомогою `identified by`;
надаю всі дозволи за допомогою оператора `grant` із указанням привілеїв (всі, тому `all`),
шаблону назви таблиць і користувача. За допомогою flush privileges змушую оновити таблицю
дозволів негайно.
```sql
MariaDB [(none)]> create user sasha@localhost identified by 'password';
Query OK, 0 rows affected (0.010 sec)

MariaDB [(none)]> grant all privileges on music_store.* to sasha@localhost;
Query OK, 0 rows affected (0.008 sec)

MariaDB [(none)]> flush privileges;
Query OK, 0 rows affected (0.005 sec)
```

тепер, зайшовши як `sasha`, бачимо, що
відображається база `music_store`.
Із нею можна виконувати всі дії.

```sql
MariaDB [(none)]> show schemas;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| music_store        |
| test               |
+--------------------+
3 rows in set (0.025 sec)
```

Але, можливо, варто його обмежити:

#### 2. Приберу всі дозволи.

Для прибрання дозволів використовується `revoke`:
```sql
MariaDB [(none)]> revoke all privileges on music_store.* from sasha@localhost;
Query OK, 0 rows affected (0.015 sec)
```

#### 3. Надам окремі дозволи на свій розсуд:

Той самий `grant`, але перелічу потрібні дозволи:
```sql
MariaDB [(none)]> grant select, insert, drop, delete, alter on music_store.* to sasha@
localhost;
Query OK, 0 rows affected (0.017 sec)
```

#### 4. Забороню видаляти що-небудь:

Так само з вибірковим `revoke`:
```sql
MariaDB [(none)]> revoke drop, delete on music_store.* from sasha@localhost;
Query OK, 0 rows affected (0.007 sec)
```

#### Перевірка:

Виберу всі поля з `bowed`, а потім спробую видалити таблицю:
```sql
MariaDB [music_store]> select * from bowed;
+------+------+------------+
| size | id   | id_product |
+------+------+------------+
|  4.9 | 1002 |       2009 |
|    4 | 1016 |       2008 |
|    4 | 1042 |       2005 |
|    4 | 1043 |       2006 |
|    4 | 1044 |       2007 |
|    4 | 1046 |       2010 |
|  4.3 | 1102 |       2003 |
|  4.7 | 1132 |       2004 |
|  4.2 | 3302 |       2001 |
|  4.5 | 6502 |       2002 |
+------+------+------------+
10 rows in set (0.000 sec)

MariaDB [music_store]> drop table bowed;
ERROR 1142 (42000): DROP command denied to user 'sasha'@'localhost' for table
`music_store`.`bowed`
```
Не можна дропати, бо я заборонив дропати. Якби був наданий відповідний дозвіл,
помилки б не виникало, про що MariaDB й сама сповіщає.

### Завдання 8
Написати різні типи підзапитів в основних командах SQL до таблиць бази даних.

#### 1. Вибрати `id` замовлення та ім'я продавця, який його обробляв:

Вибираємо `id` з таблиці `order_sheet` і як підзапит `fname` з `employee`, де `id` дорівнює `id_seller` у вибраному рядку з таблиці `order_sheet`:
```sql
MariaDB [music_store]> select id, (select fname from employee where id = order_sheet.id_seller)
	as seller_name from order_sheet;
+----+-------------+
| id | seller_name |
+----+-------------+
|  9 | Edward      |
| 10 | Edward      |
|  5 | Daniel      |
|  3 | Richard     |
|  4 | Mary        |
|  6 | Susan       |
|  1 | Linda       |
|  2 | Linda       |
|  7 | George      |
|  8 | Karen       |
+----+-------------+
10 rows in set (0.001 sec)
```
Запит успішно опрацьований, відображає те, що повинен.

#### 2. Вибрати працівників, які мають зарплату, меншу за середню

У підзапиті для визначення середньої зарплати
використаємо вже описану функцію `avg`, і порівняємо зарплату кожного
робітника з отриманим значенням.
```sql
MariaDB [music_store]> select position from employee where salary < (select avg(salary) from employee);
+-------------+
| position    |
+-------------+
| salesperson |
| salesperson |
| salesperson |
| supervisor  |
| salesperson |
| salesperson |
+-------------+
6 rows in set (0.001 sec)
```
Час підіймати зарплату деяким продавцям і наглядачу. Якщо вони добре працюють.

#### 3. Вибрати назви товарів, які коли-небудь замовляли:

Щоб дізнатися, які товари замовляли, а які --- ні, достатньо зазирнути підзапитним селектом у таблицю
order_details в пошуках `id`. За цими `id` потім вибираємо продукти:
```sql
MariaDB [music_store]> select name from product where id in (select id_product from order_details)
    -> ;
+-------------------------------------+
| name                                |
+-------------------------------------+
| "GAGA" Electric Guitar              |
| "Malyatko" Electric Guitar          |
| "Spine" Double-Neck Acoustic Guitar |
| "Shredder" Electric Guitar          |
| Ibanjek G1958 Electric Guitar       |
| Ibanjek G2958 Electric Guitar       |
| "chipupino" violin                  |
| "bambino" violin                    |
+-------------------------------------+
8 rows in set (0.001 sec)
```
Бачимо назви товарів, які вже колись продавали.
Можливо, варто замовити ще.

#### 4. Вибрати кількість струн та ціну гітар.

Ціна зберігається в таблиці `product`, тому ліземо
в неї за допомогою підзапиту, відфільтровуючи потрібні за `id_product` у `guitar`:
```sql
MariaDB [music_store]> select strings, (select price from product where id = guitar.id_product)
	as price from guitar;
+---------+--------+
| strings | price  |
+---------+--------+
|       6 | 599.99 |
|       6 | 799.99 |
|       6 | 299.99 |
|       6 | 129.99 |
|       6 | 749.99 |
|       5 | 749.99 |
|       6 | 749.99 |
|       6 | 749.99 |
|       7 | 749.99 |
|       6 | 749.99 |
+---------+--------+
10 rows in set (0.001 sec)
```
Відображається коректна інформація.

#### 5. Вибрати товар, ціна якого менша за ціну кожного товару 4-го виробника:

Тут використаємо `all` у порівнянні, шоб порівняти ціну товару з ціною кожного виробу 4-го
постачальника, вибраною за допомогою підзапиту:
```sql
MariaDB [music_store]> select * from product where price < all(select price from product
	where id_manufacturer = 4);
+------+----------+--------+----------------------------+-----------------+
| id   | quantity | price  | name                       | id_manufacturer |
+------+----------+--------+----------------------------+-----------------+
| 1004 |       20 | 129.99 | "Shredder" Electric Guitar |               8 |
+------+----------+--------+----------------------------+-----------------+
1 row in set (0.001 sec)
```
Відображається один товар, який задовольняє критерій.

### Завдання 9
Використовуючи оператори JOIN, INNERJOIN та OUTERJOIN, написати скрипти для формування зведених таблиць з вибраних даних під час створення запитів до бази даних.

#### 1. Вибрав історію кількості замовлених товарів:

Для вибірки застосовую оператор JOIN, щоб поєднати рядки таблиць `product` та `order_details`
та відобразити назву товару разом із кількістю його в замовленні.
```sql
MariaDB [music_store]> select order_details.quantity_of_goods, product.name from order_details
	join product on product.id = order_details.id_product;
+-------------------+-------------------------------------+
| quantity_of_goods | name                                |
+-------------------+-------------------------------------+
|                 5 | "GAGA" Electric Guitar              |
|                 3 | "chipupino" violin                  |
|                 4 | "Malyatko" Electric Guitar          |
|                 1 | "Spine" Double-Neck Acoustic Guitar |
|                 6 | "Shredder" Electric Guitar          |
|                 7 | Ibanjek G1958 Electric Guitar       |
|                 1 | "chipupino" violin                  |
|                 1 | "bambino" violin                    |
|                 3 | "GAGA" Electric Guitar              |
|                 1 | Ibanjek G2958 Electric Guitar       |
+-------------------+-------------------------------------+
10 rows in set (0.001 sec)
```
Зручно, тепер можна проаналізувати цей вивід та зрозуміти, що зараз актуальне.

#### 2. Вибрав характеристики та назви гітар, які ще не продавали

Щоб вибрати характеристики та назви гітар, які ще не продавали, я
спочатку вказав, що хочу обрати, а потім застосував `INNER JOIN` для поєднання
назв гітар (табл. product) із їх характеристиками (табл. guitar),
не забувши вказати умову, що цих гітар не має існувати в таблиці `order_details`.
\small
```sql
> select g.*, p.name from guitar as g inner join product as p on p.id = g.id_product
	where g.id_product NOT IN (select id_product from order_details)
+---------------+--------+-------+---------+-------+--------+------------+-------------------------------+
| scaled_length | length | width | strings | frets | id     | id_product | name                          |
+---------------+--------+-------+---------+-------+--------+------------+-------------------------------+
|          22.5 |     36 |    11 |       5 |    20 | 890896 |       1006 | Ibanjek G6958 Electric Guitar |
|          24.5 |     39 |    14 |       6 |    20 | 890898 |       1008 | Ibanjek G3958 Electric Guitar |
|            25 |     40 |    15 |       7 |    22 | 890899 |       1009 | Ibanjek G4958 Electric Guitar |
|            24 |     38 |    13 |       6 |    21 | 890900 |       1010 | Ibanjek G5958 Electric Guitar |
+---------------+--------+-------+---------+-------+--------+------------+-------------------------------+
```
\normalsize
Результат відповідає вимогам.

#### 3. Вибрати ім'я та прізвище покупця, дату замовлення та назву замовленого продукту:

Для цього можна зручно застосувати два `JOIN`-и для таблиць `buyer` та `order_details`,
приєднавши їх за `id` покупця та `id` деталей замовлення відповідно.
```sql
> select buyer.fname, buyer.lname, order_sheet.date,
(select name from product where id = order_details.id_product) as name
from order_sheet
join buyer on order_sheet.id_buyer = buyer.id
join order_details on order_details.id_order = order_sheet.id
+---------+---------+---------------------+-------------------------------------+
| fname   | lname   | date                | name                                |
+---------+---------+---------------------+-------------------------------------+
| John    | Doe     | 2023-10-13 10:00:00 | "GAGA" Electric Guitar              |
| John    | Doe     | 2023-10-13 10:00:00 | "chipupino" violin                  |
| Jane    | Smith   | 2023-10-13 11:00:00 | "Malyatko" Electric Guitar          |
| Jane    | Smith   | 2023-10-13 11:00:00 | "Spine" Double-Neck Acoustic Guitar |
| Robert  | Johnson | 2023-10-13 12:00:00 | "Shredder" Electric Guitar          |
| Robert  | Johnson | 2023-10-13 12:00:00 | Ibanjek G1958 Electric Guitar       |
| Sarah   | Duck    | 2023-10-13 13:00:00 | "chipupino" violin                  |
| Michael | Brown   | 2023-10-13 14:00:00 | "bambino" violin                    |
| Emily   | Jones   | 2023-10-13 15:00:00 | "GAGA" Electric Guitar              |
| William | Davis   | 2023-10-13 16:00:00 | Ibanjek G2958 Electric Guitar       |
+---------+---------+---------------------+-------------------------------------+
```
Красива текстова табличка відображає те, що я запитав у сервера, і нічого більше.

#### 4. Вибрати прізвища покупця та продавця, id замовлення:

Тут я знову пов'язую таблиці джойнами й виходить потрібний результат:
```sql
> select buyer.lname as buyer, employee.lname as seller, order_sheet.id
from order_sheet
join buyer on order_sheet.id_buyer = buyer.id
join employee on order_sheet.id_seller = employee.id

+---------+--------+----+
| buyer   | seller | id |
+---------+--------+----+
| Doe     | Clark  |  1 |
| Smith   | Clark  |  2 |
| Johnson | Hall   |  3 |
| Duck    | Garcia |  4 |
| Brown   | Young  |  5 |
| Jones   | Wright |  6 |
| Davis   | Harris |  7 |
| Miller  | Lee    |  8 |
| Wilson  | Turner |  9 |
| Moore   | Turner | 10 |
+---------+--------+----+
```
Результат відповідає вимогам.

#### 5. З'ясувати, з якого матеріалу кожна частина кожного інструмента:

Тут я зліплюю докупи product_has_material, product та material
із метою отримання потрібної інформації.
```sql
> select product.name, material.name, product_has_material.part_name
from product_has_material
join product on product_has_material.id_product = product.id
join material on product_has_material.id_material = material.id

+-------------------------------------+----------+-----------+
| name                                | name     | part_name |
+-------------------------------------+----------+-----------+
| "GAGA" Electric Guitar              | Oak      | fretboard |
| "GAGA" Electric Guitar              | Acacia   | body      |
| "GAGA" Electric Guitar              | Mahagoni | neck      |
| "Malyatko" Electric Guitar          | Acacia   | fretboard |
| "Malyatko" Electric Guitar          | Oak      | body      |
| "Malyatko" Electric Guitar          | Maple    | neck      |
| "Spine" Double-Neck Acoustic Guitar | Rosewood | fretboard |
| "Spine" Double-Neck Acoustic Guitar | Oak      | body      |
| "Spine" Double-Neck Acoustic Guitar | Maple    | neck      |
| "Shredder" Electric Guitar          | Rosewood | fretboard |
| "Shredder" Electric Guitar          | Rosewood | body      |
| "Shredder" Electric Guitar          | Rosewood | neck      |
+-------------------------------------+----------+-----------+
```
Можемо зручно подивитися, який інструмент із чого виготовлений.

### Завдання 10
Використовуючи функцію CASE разом із агрегатними функціями або без них, написати скрипти для створення запитів різного типу до бази даних (не менше 3).

#### 1. Відобразити імена працівників, і чи велика в них зарплата, чи мала

Порівнюю зарплати з середньою заробітною платою та виводжу
відповідно `big` і `small`.
```sql
> select fname, mname, lname,
CASE
	WHEN salary < (select avg(salary) from employee)
		then 'small'
	else 'big'
end as salary
from employee

+---------+------------+----------+--------+
| fname   | mname      | lname    | salary |
+---------+------------+----------+--------+
| Edward  | Joseph     | Turner   | small  |
| Daniel  | Eric       | Young    | big    |
| Richard | Charles    | Hall     | small  |
| Mary    | Donald     | Garcia   | small  |
| David   | Alfred     | Anderson | big    |
| Helen   | Johann     | King     | big    |
| Susan   | Fmeow      | Wright   | big    |
| Linda   | Bob        | Clark    | small  |
| George  | George     | Harris   | small  |
| Karen   | Heeeeeeeee | Lee      | small  |
+---------+------------+----------+--------+
```
Рангування зарплат, як і задумано.

#### 2. Вибірка назви товару та статусу доступності залежно від кількості:

Використовуючи `CASE`, я можу визначити статус товару й відобразити його у
зручному для клієнтів форматі:
```sql
> select name,
case
	WHEN quantity < 1
	then 'out of stock'
	when quantity < 5
	then 'running out of stock'
	else 'available'
end as availability
from product LIMIT 5
+-------------------------------------+--------------+
| name                                | availability |
+-------------------------------------+--------------+
| "GAGA" Electric Guitar              | available    |
| "Malyatko" Electric Guitar          | available    |
| "Spine" Double-Neck Acoustic Guitar | available    |
| "Shredder" Electric Guitar          | available    |
| Ibanjek G1958 Electric Guitar       | available    |
+-------------------------------------+--------------+
```
Досить зручно вийшло, можна уявити це на вебсайті.

#### 3. Вибрати кількість працівників і тих із них, які є продавцями.

Тут я записую CASE із поверненням 0 чи 1 усередині агрегатної функції sum, щоб визначити кількість
продавців серед робітників.
```sql
> SELECT
    COUNT(*) AS employees,
    sum(CASE WHEN position = 'salesperson' THEN 1 ELSE 0 END) AS salespeople
from
    employee

+-----------+-------------+
| employees | salespeople |
+-----------+-------------+
|         9 |           7 |
+-----------+-------------+
```
Порахувало, як і мало.

### Завдання 11
Використовуючи оператори UNION, INTERSECT, EXCEPT, написати скрипти для реалізації теоретико-множинних операцій реляційної алгебри в запитах вибірки даних з таблиць бази даних.

#### 1. Вибрати імена всіх людей, присутніх у базі:

Послуговуючись оператором UNION, вибираю водночас імена з
`buyer` та `employee` (це всі таблиці, які зберігають людей у базі):
```sql
> select fname, mname, lname
from buyer
union select fname, mname, lname from employee

+---------+------------+----------+
| fname   | mname      | lname    |
+---------+------------+----------+
| John    | John       | Doe      |
| Jane    | Dominique  | Smith    |
| Robert  | Charles    | Johnson  |
| Sarah   | Donald     | Duck     |
| Michael | Fred       | Brown    |
| Emily   | Michael    | Jones    |
| William | Gregory    | Davis    |
| Olivia  | Howard     | Miller   |
| James   | Ivan       | Wilson   |
| Ava     | George     | Moore    |
| Edward  | Joseph     | Turner   |
| Daniel  | Eric       | Young    |
| Richard | Charles    | Hall     |
| Mary    | Donald     | Garcia   |
| David   | Alfred     | Anderson |
| Helen   | Johann     | King     |
| Susan   | Fmeow      | Wright   |
| Linda   | Bob        | Clark    |
| George  | George     | Harris   |
| Karen   | Heeeeeeeee | Lee      |
+---------+------------+----------+
```
Маємо повний список людей.

#### 2. Вибрати такі по-батькові покупців, які не співпадають із працівниками:

Для виконання такого завдання можна використати `EXCEPT`:
```sql
> select mname from buyer EXCEPT select mname from employee;

+-----------+
| mname     |
+-----------+
| John      |
| Dominique |
| Fred      |
| Michael   |
| Gregory   |
| Howard    |
| Ivan      |
+-----------+
```
Запит обробився, інформація отримана.

#### 3. Вибрати деталі замовлень, які відбулися в жовтні 2023 року:

Вибираємо ідентифікатори замовлень 23 жовтня й використовуємо це як умову для вибору
деталей замовлення:
```sql
> select  order_details.* from order_details where id_order in (select id from orders_23_10)

+-------------------+----+----------+------------+
| quantity_of_goods | id | id_order | id_product |
+-------------------+----+----------+------------+
|                 5 |  1 |        1 |       1001 |
|                 3 |  2 |        1 |       2001 |
|                 4 |  3 |        2 |       1002 |
|                 1 |  4 |        2 |       1003 |
|                 6 |  5 |        3 |       1004 |
|                 7 |  6 |        3 |       1005 |
|                 1 |  7 |        4 |       2001 |
|                 1 |  8 |        5 |       2002 |
|                 3 |  9 |        6 |       1001 |
|                 1 | 10 |        7 |       1007 |
+-------------------+----+----------+------------+
```
Наш запит зручно виконався.

#### 4. Вибрати дати покупки гітари з `id` 1001 у жовтні 2023:

Це можна зробити, вибравши переріз таблиці order_sheet із поданням orders_23_10,
використавши `INTERSECT`:
```sql
> select date from order_sheet where id in (select id_order from order_details where id_product = 1001) intersect select date from orders_23_10;

+---------------------+
| date                |
+---------------------+
| 2023-10-13 10:00:00 |
| 2023-10-13 15:00:00 |
+---------------------+
```
Це настільки класно, що просто вау. Це --- нічого незрозумілого, лише автор здатен зрозуміти свою дизгармонію, прям мій метод написання запитів.

#### 5. Вибрати `id` усіх товарів, окрім гітар

Застосовую `EXCEPT` щоб відкинути рядки з гітарами:
```sql
> select id from product EXCEPT select id_product from guitar;

+------+
| id   |
+------+
| 6060 |
| 9097 |
| 9093 |
| 2001 |
| 2002 |
| 2003 |
| 2004 |
| 2005 |
| 2006 |
| 2007 |
| 2008 |
| 2009 |
| 2010 |
| 3303 |
| 9003 |
| 9100 |
+------+
```
Ідентифікатори гітар не відображаються.

### Завдання 12
Виконайте розділення принаймні 2 таблиць розробленої бази даних за допомогою RANG, LIST і HASH.

#### 1. Створив дублікат таблиці працівників та розділив за `id`:

```sql
create table employee_old (
  `id` int(11) NOT NULL,
  `fname` varchar(255) DEFAULT NULL,
  `mname` varchar(255) DEFAULT NULL,
  `lname` varchar(255) DEFAULT NULL,
  `salary` float DEFAULT NULL,
  `position` varchar(255) DEFAULT NULL
);

insert into employee_old select * from employee;
```

Після цього розділяю методом `RANGE`:
```sql
> alter table employee_old PARTITION BY RANGE (id)
(
	PARTITION p0 VALUES LESS THAN (1000),
	PARTITION p1 VALUES LESS THAN MAXVALUE
);
select * from employee_old PARTITION (p0)

+-----+--------+--------+--------+--------+-------------+
| id  | fname  | mname  | lname  | salary | position    |
+-----+--------+--------+--------+--------+-------------+
|   0 | Edward | Joseph | Turner |  45000 | salesperson |
| 230 | Daniel | Eric   | Young  |  70000 | salesperson |
+-----+--------+--------+--------+--------+-------------+
```
Перевірив, працює.

#### 2. Розбиваю за допомогою оператора `HASH`:

Він рівномірно розподілить елементи, зважаючи на задану кількість розділів:
```sql
> alter table employee_old PARTITION BY HASH (id) partitions 4;

> select PARTITION_NAME, TABLE_ROWS, AVG_ROW_LENGTH from information_schema.PARTITIONS
> where table_schema='music_store' and TABLE_NAME = 'employee_old'

+----------------+------------+----------------+
| PARTITION_NAME | TABLE_ROWS | AVG_ROW_LENGTH |
+----------------+------------+----------------+
| p0             |          2 |           8192 |
| p1             |          3 |           5461 |
| p2             |          3 |           5461 |
| p3             |          2 |           8192 |
+----------------+------------+----------------+
```
Побачили інформацію про розділи.

#### 3. Розділяю за допомогою `LIST`:

Створюю два розділи, кожен зі своїми значеннями `id`:
```sql
> alter TABLE employee_old
PARTITION BY LIST(id) (
    PARTITION p0 VALUES IN (0, 1020, 1001, 2101, 4321, 230),
    PARTITION p1 VALUES IN (1102, 1234, 1111, 9999)
);

select PARTITION_NAME, TABLE_ROWS, AVG_ROW_LENGTH from information_schema.PARTITIONS
where table_schema='music_store' and TABLE_NAME = 'employee_old'

+----------------+------------+----------------+
| PARTITION_NAME | TABLE_ROWS | AVG_ROW_LENGTH |
+----------------+------------+----------------+
| p0             |          6 |           2730 |
| p1             |          4 |           4096 |
+----------------+------------+----------------+
```

## 3.2. Написання збережених програмних конструкцій.

### Завдання 1. Планування подій.

Встановив планувальник подій на постійній основі та перевірив, чи він запущений

```sql
MariaDB [(none)]> SELECT ID, STATE FROM information_schema.PROCESSLIST WHERE USER='event_scheduler';
+----+------------------------+
| ID | STATE                  |
+----+------------------------+
|  1 | Waiting on empty queue |
+----+------------------------+
1 row in set (0.001 sec)
```

#### 1. Одноразова подія (видалення працівника)

Виберу * з `employee` для демонстрації працівника, якого будемо
видаляти.
```sql
MariaDB [music_store]> select * from employee;
+------+---------+------------+----------+--------+-------------+
| id   | fname   | mname      | lname    | salary | position    |
+------+---------+------------+----------+--------+-------------+
|    0 | Edward  | Joseph     | Turner   |  45000 | salesperson |
|  230 | Daniel  | Eric       | Young    |  70000 | salesperson |
| 1001 | Richard | Charles    | Hall     |  50000 | salesperson |
| 1020 | Mary    | Donald     | Garcia   |  45000 | salesperson |
| 1102 | David   | Alfred     | Anderson |  60000 | manager     |
| 1111 | Helen   | Johann     | King     |  70000 | technician  |
| 1234 | Susan   | Fmeow      | Wright   |  60000 | salesperson |
| 2101 | Linda   | Bob        | Clark    |  55000 | supervisor  |
| 4321 | George  | George     | Harris   |  55000 | salesperson |
| 9999 | Karen   | Heeeeeeeee | Lee      |  50000 | salesperson |
+------+---------+------------+----------+--------+-------------+
10 rows in set (0.005 sec)
```

Створюю подію за 10 секунд після поточного моменту:
```sql
MariaDB [music_store]> create event delete_1102_manager
    -> on schedule at current_timestamp + interval 10 second
    -> do
    -> delete from employee where id = 1102;
Query OK, 0 rows affected (0.007 sec)

MariaDB [music_store]> select * from employee where id = 1102;
Empty set (0.000 sec)
```
Ця подія зникла з таблиці подій після виконання, як і зник наш працівник.

#### 2. Неусунена одноразова подія --- підвищення зарплати:

Додаю `on completion preserve`, щоб подія не видалялась із інформаційної
схеми:
```sql
create event salary_increase
on schedule at current_timestamp + interval 10 second
on completion preserve
do
    update employee set salary = salary + 5

MariaDB [music_store]> select event_name, event_type, status from information_schema.events;
+-------------------+------------+----------+
| event_name        | event_type | status   |
+-------------------+------------+----------+
| preserved_onetime | ONE TIME   | DISABLED |
| salary_increase   | ONE TIME   | DISABLED |
+-------------------+------------+----------+
2 rows in set (0.002 sec)
```
Бачимо, що подія збереглася після виконання.

#### 3. Повторювана подія --- збільшення цін на товари:

Задаю події початок, кінець та інтервал виконання в наступному
лістингу:
```sql
> create event price_increase
on schedule every 1 minute
starts current_timestamp
ends current_timestamp + interval 1 hour
do
    update product set price = price + price * 1/100

MariaDB [music_store]> select price from product;
+---------+
| price   |
+---------+
| 787.787 |
| 1050.39 |
| 393.887 |
| 170.677 |
| 984.737 |
| 984.737 |
| 984.737 |
| 984.737 |
| 984.737 |
| 984.737 |
| 459.537 |
| 459.537 |
| 459.537 |
| 459.537 |
| 459.537 |
| 459.537 |
| 459.537 |
| 459.537 |
| 459.537 |
| 459.537 |
| 1181.69 |
| 262.587 |
| 459.537 |
| 525.187 |
| 656.487 |
+---------+
25 rows in set (0.001 sec)

MariaDB [music_store]> select price from product limit 5;
+---------+
| price   |
+---------+
| 803.621 |
|  1071.5 |
| 401.804 |
| 174.107 |
| 1004.53 |
+---------+
5 rows in set (0.001 sec)
```
Ціни ростуть, а зарплати, на жаль, не ростуть.

#### 4. Регулярний бекап бази даних

Щоб уникнути неприємностей та неочікуваних втрат даних, я додав до `crontab` створення резервної копії бази.
Це не планування подій безпосередньо в СКБД, але я вважаю це важливою частиною робот.
```
0 */2 * * * /usr/bin/mariadb-backup --backup --user=root --databases=music_store
```
Ця команда виконується кожні дві години, і робить резервну копію виключно бази `music_store`.

### Завдання 2. Тригери.

#### 1. Тригер, який оновлює кількість проданих товарів

Він додає до `@items_sold` 1 щоразу, коли створюється новий рядок
в `order_details`:
```sql
> create trigger sold_items_updater before insert on order_details
	for each row
	set @items_sold = @items_sold + new.quantity_of_goods;

MariaDB [music_store]> select @items_sold
    -> ;
+-------------+
| @items_sold |
+-------------+
|          32 |
+-------------+
1 row in set (0.000 sec)

MariaDB [music_store]> insert into order_details (quantity_of_goods, id_order, id_product)
	values (4, 7, 1003);
Query OK, 1 row affected (0.008 sec)

MariaDB [music_store]> select @items_sold
    -> ;
+-------------+
| @items_sold |
+-------------+
|          36 |
+-------------+
1 row in set (0.000 sec)
```

#### 2. Тригер, який не дає замовити більше товару, ніж є в наявності

Він має запобігати незручностям у процесі замовлення, наприклад,
коли людина замовляє 52 медіатори, а виявляється, що в наявності їх 4.
```sql
delimiter //
create TRIGGER order_details_bi before insert on order_details
	FOR EACH ROW
	BEGIN
	IF (select quantity from product where id = new.id_product) < new.quantity_of_goods THEN
		SIGNAL SQLSTATE '50001' SET MESSAGE_TEXT = "Not enough items in stock!";
	END IF;
	END;//
delimiter ;
```

Для його перевірки я використав таку трансакцію:
```sql
delimiter //
START TRANSACTION;

set @product_id = 2006;
set @order_date = CURRENT_TIMESTAMP;
set @order_quantity = 25;

    INSERT INTO order_sheet (date, id_buyer, id_seller) values (@order_date, 9, 230);
    select @order_id := id from order_sheet where `date` regexp @order_date;

    INSERT INTO order_details (id_product, quantity_of_goods, id_order)
    	VALUES (@product_id, @order_quantity, @order_id);

    IF EXISTS (SELECT 1 FROM order_details WHERE id_product = @product_id
    	AND id_order = @order_id) THEN
    	SAVEPOINT details_set;
    ELSE
	rollback;
    END IF;

    UPDATE product SET quantity = @current_stock - @order_quantity WHERE id = @product_id;

    COMMIT;
//
delimiter ;
```

Після запуску маємо:
```
ERROR 1644 (50001) at line 2: Not enough items in stock!
```
Отже, тригер працює та не дасть замовити більше товару, ніж
є в наявності.

### Завдання 3. Збережені процедури.

#### 1. Процедура рангування зарплат:

Тут простий оператор умовного переходу визначає чи зарплата
велика, чи мала, та виводить результат.
```sql
> DELIMITER //

create procedure rank_wages ()

begin
select fname, mname, lname,
CASE
	WHEN salary < (select avg(salary) from employee)
		then 'small'
	else 'big'
end as salary
from employee;

end//

MariaDB [music_store]> call rank_wages();
+---------+------------+--------+--------+
| fname   | mname      | lname  | salary |
+---------+------------+--------+--------+
| Edward  | Joseph     | Turner | small  |
| Daniel  | Eric       | Young  | big    |
| Richard | Charles    | Hall   | small  |
| Mary    | Donald     | Garcia | small  |
| Helen   | Johann     | King   | big    |
| Susan   | Fmeow      | Wright | big    |
| Linda   | Bob        | Clark  | small  |
| George  | George     | Harris | small  |
| Karen   | Heeeeeeeee | Lee    | small  |
+---------+------------+--------+--------+
9 rows in set (0.004 sec)
Query OK, 0 rows affected (0.005 sec)
```
Бачимо, що, як і прописано у процедурі,
поле `salary` складається тільки зі значень
`small` та `big`.

#### 2. Процедура для визначення матеріалів за `id` товару:

Ідея полягає в поєднанні таблиць product і material
за допомогою `product_has_material`
таким чином, щоб можна було ввести `id` товару й отримати
матеріали, з яких складаються його частини, та назви
цих частин.

```sql
> DELIMITER //
create procedure get_materials (input_id int)
begin

select material.name as material, product_has_material.part_name
from product_has_material
join product on product_has_material.id_product = product.id
join material on product_has_material.id_material = material.id
where id_product = input_id;

end //

MariaDB [music_store]> call get_materials(1001);
+----------+-----------+
| material | part_name |
+----------+-----------+
| Oak      | fretboard |
| Acacia   | body      |
| Mahagoni | neck      |
+----------+-----------+
3 rows in set (0.001 sec)
Query OK, 0 rows affected (0.002 sec)
```
Вона значно спростить отримання інформації про матеріали товару.

#### 3. Процедура, яка полегшує вибірку замовлень до чи після обіду.

Тут я скористався часовими функціями та операторам умовного
переходу `CASE`:
```sql
> delimiter //
create procedure sales(in param varchar(20))
begin
    case
    when (param = 'am') then
	select * from order_sheet where hour(date) < 12;
    when (param = 'pm') then
	select * from order_sheet where hour(date) > 12;
    else
	select * from order_sheet;
    end case;
end//

MariaDB [music_store]> call sales('am');
+---------------------+----+----------+-----------+
| date                | id | id_buyer | id_seller |
+---------------------+----+----------+-----------+
| 2023-10-13 10:00:00 |  1 |        1 |      2101 |
| 2023-10-13 11:00:00 |  2 |        2 |      2101 |
+---------------------+----+----------+-----------+
2 rows in set (0.001 sec)

Query OK, 0 rows affected (0.001 sec)

MariaDB [music_store]> call sales('pm');
+---------------------+----+----------+-----------+
| date                | id | id_buyer | id_seller |
+---------------------+----+----------+-----------+
| 2023-10-13 13:00:00 |  4 |        4 |      1020 |
| 2023-10-13 14:00:00 |  5 |        5 |       230 |
| 2023-10-13 15:00:00 |  6 |        6 |      1234 |
| 2023-10-13 16:00:00 |  7 |        7 |      4321 |
| 2023-10-13 17:00:00 |  8 |        8 |      9999 |
| 2023-10-13 18:00:00 |  9 |        9 |         0 |
| 2023-10-13 19:00:00 | 10 |       10 |         0 |
+---------------------+----+----------+-----------+
7 rows in set (0.000 sec)

Query OK, 0 rows affected (0.000 sec)
```
Це може бути корисним для аналітики та кращого налаштування графіку роботи.

#### 4. Функція, яка повертає кількість продавців, які нічого не продали:

У функції використаю вибірку `count(*)`  з `employee`, де `id` немає
(`not in`) в `order_sheet` і регулярний вираз посади "sales":
```sql
> DELIMITER //
create function get_leeches ()
returns int
deterministic
begin

declare var int;
select count(*) into var from employee where id not in (select id_seller from order_sheet)
	and position regexp "sales";

return var;
end //

MariaDB [music_store]> set @lazy = get_leeches();
Query OK, 0 rows affected (0.002 sec)

MariaDB [music_store]> select @lazy;
+-------+
| @lazy |
+-------+
|     0 |
+-------+
1 row in set (0.000 sec)
```
Всі добре працюють, і це добре.

#### 5. Функція для визначення суми цін проданих товарів:

Ось сама функція:
```sql
> DELIMITER //
create function sold_sum ()
returns float
deterministic
begin
declare sold_item_sum float ;
select sum(price * (select sum(quantity_of_goods) from order_details where id_product = product.id))
	into sold_item_sum from product where id in (select id_product from order_details) ;
return sold_item_sum;
end //

MariaDB [music_store]> set @sum = sold_sum(); select @sum;
Query OK, 0 rows affected (0.001 sec)
+--------------+
| @sum         |
+--------------+
| 43006.515625 |
+--------------+
1 row in set (0.000 sec)
```

1. `CREATE FUNCTION sold_sum() RETURNS FLOAT DETERMINISTIC`: Починає визначення функції з ім'ям `sold_sum`, яка повертає значення типу `FLOAT`. Вказується ключове слово `DETERMINISTIC`, що означає, що функція завжди повертає одне й те саме значення для одних і тих же вхідних даних.
2. `DECLARE sold_item_sum FLOAT;`: Оголошується локальна змінна `sold_item_sum` типу `FLOAT`, яка використовуватиметься для збереження суми проданих товарів.
3. `SELECT SUM(price * (SELECT SUM(quantity_of_goods) FROM order_details WHERE id_product = product.id)) INTO sold_item_sum FROM product WHERE id IN (SELECT id_product FROM order_details);`: Виконується вкладений запит, який обчислює суму проданих товарів для кожного товару. Це виконується за допомогою вкладеного підзапиту, який рахує суму кількості проданих товарів для кожного товару в таблиці `order_details`. Результат записується у змінну `sold_item_sum`.
4. `RETURN sold_item_sum;`: Повертає отриману суму проданих товарів.

#### 6. Процедура для продажу товару

Ця процедура отримує необхідні параметри типу `id` продукта, продавця, покупця, та кількість проданого,
додає замовлення, тоді дістає його ідентифікатор і створює деталі замовлення з посиланням на нього.
Якщо вони існують, то зберігається, якщо ж ні --- відкочується. Після успішного додання деталей замовлення
процедура віднімає продану кількість від кількості товару в базі.
```sql
delimiter //
drop procedure sell_an_item;
create procedure sell_an_item(in product_id int, in quant int, in seller_id int, in buyer_id int)
begin
    set @order_date = CURRENT_TIMESTAMP;
    SELECT @current_stock := quantity FROM product WHERE id = product_id;

START TRANSACTION;

    INSERT INTO order_sheet (date, id_buyer, id_seller) values (@order_date, buyer_id, seller_id);
    select @order_id := id from order_sheet where `date` regexp @order_date;

    INSERT INTO order_details (id_product, quantity_of_goods, id_order)
    	VALUES (product_id, quant, @order_id);

    IF EXISTS (SELECT 1 FROM order_details WHERE id_product = product_id
    	AND id_order = @order_id) THEN
    	SAVEPOINT details_set;
    ELSE
	rollback;
    END IF;

    UPDATE product SET quantity = @current_stock - quant WHERE id = product_id;

    COMMIT;
end//
delimiter ;
call sell_an_item(2006, 5, 230, 9);
```

Думаю, це найкорисніша процедура з усіх, які я написав,
бо вона значно полегшує облік продажів (а це дуже важливо).

#### 7. Процедура для додання складного товару, типу гітари чи скрипки, де запис складається з двох таблиць.

Концепція проста: спочатку додається продукт, а потім додаткова інформація
в таблиці відповідного інструмента.
```sql
DELIMITER ;;
drop procedure if exists insert_complex;
CREATE DEFINER=`sasha`@`localhost` PROCEDURE `insert_complex`(in q int, in p float, in n varchar(255), in im int, in t varchar(255), in i int)
begin

START TRANSACTION;

    INSERT INTO product (quantity, price, name, id_manufacturer) values (q, p, n, im);
    select @id := id from product where name = n and quantity = q and price = p;

    if (t = 'guitar') then
        INSERT into guitar (scaled_length, length, width, strings, frets, id_product, id) values (25.5, 41, 14, 6, 22, @id, i);
    elseif (t = 'bowed') then
        INSERT into bowed (size, id_product, id) values (4, @id, i);
    else
		SIGNAL SQLSTATE '50001' SET MESSAGE_TEXT = "quantity, price, name, id_manuf, type (guitar|bowed), id";
    end if;

    COMMIT;
end ;;
DELIMITER ;

call insert_complex(14, 238.213, 'moew guitar', 1, 'guitar', 382984);

...

| id   | quantity | price      | name                                | id_manufacturer |
...
| 9107 |       14 |    238.213 | moew guitar                         |               1 |

...

| scaled_length | length | width | strings | frets | id     | id_product |
...
|          25.5 |     41 |    14 |       6 |    22 | 382984 |       9107 |
```
Тепер можна зручно додавати  гітари й інші інструменти до бази.

### Завдання 4. Курсори.

#### 1. Процедура з курсором, яка вибирає номери телефону виробників і записує їх у змінну, розділяючи `;`:

Спочатку створюю потрібні змінні, а далі курсор із `select phone from manufacturer`,
відкриваю його та проходжусь по таблиці `manufacturer`, конкатенуючи номери телефонів.
```sql
> DELIMITER $$
drop procedure if exists createphoneList $$
CREATE PROCEDURE createphoneList (
	INOUT phonelist varchar(4000)
)
BEGIN
	DECLARE finished INTEGER DEFAULT 0;
	DECLARE phone_var varchar(100) DEFAULT "";

        DEClARE curPhone
                CURSOR FOR
                        SELECT phone FROM manufacturer;


        DECLARE CONTINUE HANDLER
        FOR NOT FOUND SET finished = 1;

        OPEN curPhone;

        getphone: LOOP
                FETCH curPhone INTO phone_var;
                IF finished = 1 THEN
                        LEAVE getphone;
                END IF;

                SET phoneList = CONCAT(phone_var,";",phonelist);
        END LOOP getphone;
        CLOSE curPhone;
END


MariaDB [music_store]> set @phonelist = ""; call createphonelist(@phonelist); select @phonelist;
Query OK, 0 rows affected (0.000 sec)
Query OK, 0 rows affected (0.000 sec)
+------------------------------------------------------------------------------------------------------+
| @phonelist                                                                                           |
+------------------------------------------------------------------------------------------------------+
| 952431122;953448769;982435342;953433421;982346789;952423345;952387645;982349876;683245678;952341234; |
+------------------------------------------------------------------------------------------------------+
1 row in set (0.000 sec)
```
Список сформувався, як треба.

#### 2. Процедура, яка вибирає `id` клієнта та суму його замовлень:

Курсор вибирає ідентифікатор покупця зі списку замовлень,
який використовується в циклі під час обчислення суми замовлень.

```sql
> DELIMITER //
drop PROCEDURE if exists calculate_total_order_amounts //
CREATE PROCEDURE calculate_total_order_amounts()
BEGIN
    DECLARE done INT DEFAULT 0;
    DECLARE customer_id INT;
    DECLARE total_amount DECIMAL(10, 2);

    DECLARE customer_cursor
    	CURSOR FOR
    		select distinct id_buyer from order_sheet;

    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = 1;

    OPEN customer_cursor;

    read_customers: LOOP
        FETCH customer_cursor INTO customer_id;

        IF done THEN
            LEAVE read_customers;
        END IF;

        -- Обчислення загальної суми цін товарів для кожного клієнта
        SET total_amount = (
            SELECT SUM(product.price * order_details.quantity_of_goods)
            FROM order_sheet
            JOIN order_details ON order_sheet.id = order_details.id_order
            JOIN product ON order_details.id_product = product.id
            WHERE order_sheet.id_buyer = customer_id
        );

	select customer_id, total_amount;
    END LOOP;

    CLOSE customer_cursor;

END //
DELIMITER ;

MariaDB [music_store]> call calculate_total_order_amounts;
+-------------+--------------+
| customer_id | total_amount |
+-------------+--------------+
|           1 |      9660.37 |
+-------------+--------------+
1 row in set (0.002 sec)
+-------------+--------------+
| customer_id | total_amount |
+-------------+--------------+
|           2 |      8348.51 |
+-------------+--------------+
1 row in set (0.003 sec)
+-------------+--------------+
| customer_id | total_amount |
+-------------+--------------+
|           3 |     14383.19 |
+-------------+--------------+
1 row in set (0.003 sec)
+-------------+--------------+
| customer_id | total_amount |
+-------------+--------------+
|           4 |       834.84 |
+-------------+--------------+
1 row in set (0.004 sec)
+-------------+--------------+
| customer_id | total_amount |
+-------------+--------------+
|           5 |       834.84 |
+-------------+--------------+
1 row in set (0.004 sec)
+-------------+--------------+
| customer_id | total_amount |
+-------------+--------------+
|           6 |      4293.51 |
+-------------+--------------+
1 row in set (0.005 sec)
+-------------+--------------+
| customer_id | total_amount |
+-------------+--------------+
|           7 |      4651.26 |
+-------------+--------------+
1 row in set (0.005 sec)
+-------------+--------------+
| customer_id | total_amount |
+-------------+--------------+
|           8 |         NULL |
+-------------+--------------+
1 row in set (0.006 sec)
+-------------+--------------+
| customer_id | total_amount |
+-------------+--------------+
|           9 |         NULL |
+-------------+--------------+
1 row in set (0.006 sec)
+-------------+--------------+
| customer_id | total_amount |
+-------------+--------------+
|          10 |         NULL |
+-------------+--------------+
1 row in set (0.007 sec)
Query OK, 0 rows affected (0.007 sec)
```
Вивелась сума замовлень кожного клієнта,
тепер це можна проаналізувати, або викинути.

### Завдання 5. Транзакції. Блокування. Точки збереження.

#### Трансакції

#### 1. Трансакція для видалення покупця з усіма його замовленнями:

```sql
MariaDB [music_store]> start TRANSACTION;
Query OK, 0 rows affected (0.000 sec)

MariaDB [music_store]> delete from order_sheet where id_buyer = 4;
Query OK, 1 row affected (0.006 sec)

MariaDB [music_store]> delete from buyer where id = 4;
Query OK, 1 row affected (0.000 sec)

MariaDB [music_store]> commit;
Query OK, 0 rows affected (0.006 sec)
```

Якби я зробив тут помилку, то втратив би інформацію
про замовлення іншого покупця, а перебування у трансакції
б дозволило мені повернути все, як було.

#### 2. Трансакція видалення товару (гітари).

```sql
MariaDB [music_store]> start transaction;
Query OK, 0 rows affected (0.000 sec)

MariaDB [music_store]> select * from guitar;
+---------------+--------+-------+---------+-------+--------+------------+
| scaled_length | length | width | strings | frets | id     | id_product |
+---------------+--------+-------+---------+-------+--------+------------+
|          25.5 |     41 |    14 |       6 |    22 | 890891 |       1001 |
|         24.75 |     39 |    13 |       6 |    24 | 890892 |       1002 |
|            26 |     42 |    15 |       6 |    22 | 890893 |       1003 |
|            25 |     40 |    14 |       6 |    21 | 890894 |       1004 |
|          25.5 |     41 |    14 |       6 |    24 | 890895 |       1005 |
|          22.5 |     36 |    11 |       5 |    20 | 890896 |       1006 |
|            23 |     37 |    12 |       6 |    22 | 890897 |       1007 |
|          24.5 |     39 |    14 |       6 |    20 | 890898 |       1008 |
|            25 |     40 |    15 |       7 |    22 | 890899 |       1009 |
|            24 |     38 |    13 |       6 |    21 | 890900 |       1010 |
+---------------+--------+-------+---------+-------+--------+------------+
10 rows in set (0.001 sec)

MariaDB [music_store]> delete from product where id = (select id_product from guitar where id = 890900);
Query OK, 1 row affected (0.002 sec)

MariaDB [music_store]> delete from guitar where id = 890890;
Query OK, 0 rows affected (0.001 sec)

MariaDB [music_store]> delete from guitar where id = 890900;
Query OK, 1 row affected (0.001 sec)

MariaDB [music_store]> commit;
Query OK, 0 rows affected (0.005 sec)
```

Тут я випадково ввів не той `id` гітари, нічого не видалилося
тільки тому що такої гітари не існувало, але якби була, то
без трансакції було б незручно.

#### Блокування

#### 1. Нехай потрібно зробити звіт про характеристики гітар конкретно зараз,
тоді можна заблокувати таблицю `guitar`, щоб інші не змогли туди записати за
цей час:

```sql
MariaDB [music_store]> lock tables guitar read;
Query OK, 0 rows affected (0.000 sec)

MariaDB [music_store]> select * from guitar;
+---------------+--------+-------+---------+-------+--------+------------+
| scaled_length | length | width | strings | frets | id     | id_product |
+---------------+--------+-------+---------+-------+--------+------------+
|          25.5 |     41 |    14 |       6 |    22 | 890891 |       1001 |
|         24.75 |     39 |    13 |       6 |    24 | 890892 |       1002 |
|            26 |     42 |    15 |       6 |    22 | 890893 |       1003 |
|            25 |     40 |    14 |       6 |    21 | 890894 |       1004 |
|          25.5 |     41 |    14 |       6 |    24 | 890895 |       1005 |
|          22.5 |     36 |    11 |       5 |    20 | 890896 |       1006 |
|            23 |     37 |    12 |       6 |    22 | 890897 |       1007 |
|          24.5 |     39 |    14 |       6 |    20 | 890898 |       1008 |
|            25 |     40 |    15 |       7 |    22 | 890899 |       1009 |
|            24 |     38 |    13 |       6 |    21 | 890900 |       1010 |
+---------------+--------+-------+---------+-------+--------+------------+
10 rows in set (0.000 sec)

MariaDB [music_store]> insert into guitar values(0,1,2,34,444);
ERROR 1099 (HY000): Table 'guitar' was locked with a READ lock and can't be updated
MariaDB [music_store]> unlock tables ;
Query OK, 0 rows affected (0.000 sec)
```
Видно, що не можна зараз додати нові дані до гітар, тому можна
не перейматись через їх нецілісність.

#### 2. Нехай треба додати новий товар від нового виробника.

Оскільки `id` в цих таблицях встановленні з `auto_increment` (і взагалі щоб не виникло конфлікту, якщо хтось паралельно вирішив додати той самий товар),
логічно буде заблокувати їх на час додання товару:

```sql
MariaDB [music_store]> lock tables manufacturer WRITE, product WRITE ;
Query OK, 0 rows affected (0.001 sec)

MariaDB [music_store]> insert into manufacturer (address_code , phone , name )
	values(84848, 923128844, 'libretone');
Query OK, 1 row affected (0.018 sec)

MariaDB [music_store]> INS
INSENSITIVE    INSERT         INSERT_METHOD  INSTR
MariaDB [music_store]> select id from manufacturer where name regexp "libret"
    -> ;
+----+
| id |
+----+
| 13 |
+----+
1 row in set (0.000 sec)

MariaDB [music_store]> insert into product(quantity, price, name , id_manufacturer )
	values (23, 1111111111, 'table', 13);
Query OK, 1 row affected (0.006 sec)

MariaDB [music_store]> unlock tables ;
Query OK, 0 rows affected (0.000 sec)
```

#### Точки збереження

#### 1. Трансакція додання замовлення

У цій трансакції є перевірка того, чи встановилися деталі замовлення. Якщо ні, вона повертається до точки збереження, де встановлена тільки основна інформація про замовлення. Також тут є перевірка, чи кількість товару достатня, якщо ні --- відбувається відкат до початкового стану.
```sql
delimiter //
START TRANSACTION;

set @product_id = 2006;
SELECT @current_stock := quantity FROM product WHERE id = @product_id;

IF @current_stock >= 5 THEN
    set @order_date = CURRENT_TIMESTAMP;

    INSERT INTO order_sheet (date, id_buyer, id_seller) values (@order_date, 9, 230);
    savepoint order_set;

    select @order_id := id from order_sheet where date regexp @order_date;
    INSERT INTO order_details (id_product, quantity_of_goods, id_order)
    	VALUES (@product_id, 5, @order_id);

    IF EXISTS (SELECT 1 FROM order_details WHERE id_product = @product_id
    	AND id_order = @order_id) THEN
    	SAVEPOINT details_set;
    ELSE
	rollback to order_set;
    END IF;

    UPDATE product SET quantity = @current_stock - 5 WHERE id = @product_id;

    COMMIT;
ELSE
    ROLLBACK;
END IF;
//
delimiter ;
```
Так краще для цілісності бази.

#### 2. Трансакція з помилковим видаленням покупця з бази і відповідним поверненням до точки збереження.

Видаляю 3-го покупця й випадково замість 6-го прибираю 5.
Повертаюсь до точки збереження та почуваюся зручно.
```sql
MariaDB [music_store]> start transaction;
Query OK, 0 rows affected (0.000 sec)

MariaDB [music_store]> delete from buyer where id = 3;
Query OK, 1 row affected (0.001 sec)

MariaDB [music_store]> savepoint del_3;
Query OK, 0 rows affected (0.000 sec)

MariaDB [music_store]> delete from buyer where id = 5;
Query OK, 1 row affected (0.001 sec)

MariaDB [music_store]> rollback to del_3;
Query OK, 0 rows affected (0.000 sec)

MariaDB [music_store]> delete from buyer where id = 6;
Query OK, 1 row affected (0.001 sec)

MariaDB [music_store]> select * from buyer;
+----+---------+-----------+--------+
| id | fname   | mname     | lname  |
+----+---------+-----------+--------+
|  1 | John    | John      | Doe    |
|  2 | Jane    | Dominique | Smith  |
|  5 | Michael | Fred      | Brown  |
|  7 | William | Gregory   | Davis  |
|  8 | Olivia  | Howard    | Miller |
|  9 | James   | Ivan      | Wilson |
| 10 | Ava     | George    | Moore  |
+----+---------+-----------+--------+
7 rows in set (0.000 sec)

MariaDB [music_store]> commit;
Query OK, 0 rows affected (0.023 sec)
```
Якби це відбувалося не у трансакції, то ми б
утратили дані покупця, який нам іще потрібен.
Використання трансакції дало змогу легко
виправити помилку.

## 3.3. Аналіз та оптимізація запитів.

#### створення індексів

Вибираємо працівників, у яких ім'я як `john%`:
```sql
EXPLAIN select * from employee where fname like "john%";

+------+-------------+----------+------+---------------+------+---------+------+------+-------------+
| id   | select_type | table    | type | possible_keys | key  | key_len | ref  | rows | Extra       |
+------+-------------+----------+------+---------------+------+---------+------+------+-------------+
|    1 | SIMPLE      | employee | ALL  | NULL          | NULL | NULL    | NULL | 9    | Using where |
+------+-------------+----------+------+---------------+------+---------+------+------+-------------+
```

Додамо індекс імен:
\footnotesize
```sql
alter table employee add INDEX fname (fname);
EXPLAIN select * from employee where fname like "john%";

+------+-------------+----------+-------+---------------+-------+---------+------+------+-----------------------+
| id   | select_type | table    | type  | possible_keys | key   | key_len | ref  | rows | Extra                 |
+------+-------------+----------+-------+---------------+-------+---------+------+------+-----------------------+
|    1 | SIMPLE      | employee | range | fname         | fname | 1023    | NULL | 1    | Using index condition |
+------+-------------+----------+-------+---------------+-------+---------+------+------+-----------------------+
```
\normalsize
Бачимо, що значення `rows` змінилося з 9 до 1 і тип з'єднання тепер не `ALL`, а `range`, `key` тепер --- `fname`.

#### використання змінних користувача

\small
```sql
EXPLAIN select * from order_sheet where date <= CURDATE();

+------+-------------+-------------+------+---------------+------+---------+------+------+-------------+
| id   | select_type | table       | type | possible_keys | key  | key_len | ref  | rows | Extra       |
+------+-------------+-------------+------+---------------+------+---------+------+------+-------------+
|    1 | SIMPLE      | order_sheet | ALL  | NULL          | NULL | NULL    | NULL | 10   | Using where |
+------+-------------+-------------+------+---------------+------+---------+------+------+-------------+

set @datum = CURDATE();
EXPLAIN select * from order_sheet where date <= @datum;
+------+-------------+-------------+------+---------------+------+---------+------+------+-------------+
| id   | select_type | table       | type | possible_keys | key  | key_len | ref  | rows | Extra       |
+------+-------------+-------------+------+---------------+------+---------+------+------+-------------+
|    1 | SIMPLE      | order_sheet | ALL  | NULL          | NULL | NULL    | NULL | 10   | Using where |
+------+-------------+-------------+------+---------------+------+---------+------+------+-------------+
```
\normalsize
Тут нічого не змінилося, крім того, що ми тепер зберегли значення дати і не потрібно
виконувати обчислення знову. Відповідно, якби це були довгі та затратні процеси, ми
б отримали велику перевагу від зберігання результату.

#### модифікація запиту

\scriptsize
```sql
explain select * from product where id in (select id_product from guitar ) limit 1 ;

+------+-------------+---------+--------+---------------+------------+---------+-------------------------------+------+--------------------------+
| id   | select_type | table   | type   | possible_keys | key        | key_len | ref                           | rows | Extra                    |
+------+-------------+---------+--------+---------------+------------+---------+-------------------------------+------+--------------------------+
|    1 | PRIMARY     | guitar  | index  | id_product    | id_product | 5       | NULL                          | 10   | Using where; Using index |
|    1 | PRIMARY     | product | eq_ref | PRIMARY       | PRIMARY    | 4       | music_store.guitar.id_product | 1    |                          |
+------+-------------+---------+--------+---------------+------------+---------+-------------------------------+------+--------------------------+

explain select * from product where id = (select id_product from guitar limit 1) ;
+------+-------------+---------+-------+---------------+------------+---------+-------+------+-------------+
| id   | select_type | table   | type  | possible_keys | key        | key_len | ref   | rows | Extra       |
+------+-------------+---------+-------+---------------+------------+---------+-------+------+-------------+
|    1 | PRIMARY     | product | const | PRIMARY       | PRIMARY    | 4       | const | 1    |             |
|    2 | SUBQUERY    | guitar  | index | NULL          | id_product | 5       | NULL  | 10   | Using index |
+------+-------------+---------+-------+---------------+------------+---------+-------+------+-------------+
```
\normalsize

Можна обмежувати певні запити, наприклад ті, що наведені вище, роблять те саме, але другий краще, бо вибирає тільки один рядок із відповідним критерієм.

#### розділення таблиць

У мене вже була розділена таблиця `employee_old`, тому використовую її:
\small
```sql
explain select * from employee_old where salary < 50000;
explain select * from employee_old partition(p0) where salary < 50000;

+------+-------------+--------------+------+---------------+------+---------+------+------+-------------+
| id   | select_type | table        | type | possible_keys | key  | key_len | ref  | rows | Extra       |
+------+-------------+--------------+------+---------------+------+---------+------+------+-------------+
|    1 | SIMPLE      | employee_old | ALL  | NULL          | NULL | NULL    | NULL | 10   | Using where |
+------+-------------+--------------+------+---------------+------+---------+------+------+-------------+
+------+-------------+--------------+------+---------------+------+---------+------+------+-------------+
| id   | select_type | table        | type | possible_keys | key  | key_len | ref  | rows | Extra       |
+------+-------------+--------------+------+---------------+------+---------+------+------+-------------+
|    1 | SIMPLE      | employee_old | ALL  | NULL          | NULL | NULL    | NULL | 2    | Using where |
+------+-------------+--------------+------+---------------+------+---------+------+------+-------------+
```
\normalsize
Якщо ми знаємо, що дані точно в певному розділі, то використання тільки його
для вибірки дасть великий приріст у швидкості.

## Аудит бази даних

Я установив плагін для MariaDB, який забезпечує функціонал аудиту бази даних,
та увімкнув його:
```sql
MariaDB [music_store]> INSTALL SONAME 'server_audit';
MariaDB [music_store]> SET GLOBAL server_audit_events = 'CONNECT,QUERY,TABLE';
MariaDB [music_store]> set global server_audit_logging = ON;
```

Можна переглянути журнал того, що який користувач запитував у сервера:
\small
```
[amnesia var]# cat /var/lib/mysql/server_audit.log
20231127 22:27:54,amnesia,root,localhost,10,684,QUERY,music_store,'set global server_audit_logging = ON',0
20231127 22:27:56,amnesia,root,localhost,10,685,QUERY,music_store,'SET GLOBAL server_audit_events = \'CONNECT,QUERY,TABLE\'',0
20231127 22:28:02,amnesia,root,localhost,10,686,QUERY,music_store,'SHOW GLOBAL VARIABLES LIKE \'server_audit%\'',0
20231127 22:29:20,amnesia,root,localhost,11,0,CONNECT,music_store,,0
20231127 22:29:20,amnesia,root,localhost,11,687,QUERY,music_store,'show databases',0
20231127 22:29:20,amnesia,root,localhost,11,688,QUERY,music_store,'show tables',0
20231127 22:29:20,amnesia,root,localhost,11,702,QUERY,music_store,'select @@version_comment limit 1',0
20231127 22:33:08,amnesia,root,localhost,11,0,DISCONNECT,music_store,,0
20231127 22:33:15,amnesia,root,localhost,10,0,DISCONNECT,music_store,,0
```
\normalsize
Ця інформація може бути корисною в багатьох випадках.

# Висновки

### Побудова моделей БД

Щоб побудувати нормальну модель (концептуальну
чи фізичну),
потрібно дуже добре проаналізувати предметну
область, щоб потім не виникало незручностей.
На жаль, усе продумати наперед практично неможливо,
але це не значить, що не варто виділяти багато часу
на найпершому етапі.

Із побудовою фізичної моделі вже стає
більш-менш зрозуміло, як що організоване в
базі, і стає видно багато проблем зі
зв'язками. Але навіть після ніби вирішення всіх
проблем ми стикаємося з ними знову, коли вже
починаєм активно вжиткувати базою.

### Робота з базою

Курс організації баз даних дав мені базові
інструменти для зручної взаємодії з БД:

- Я навчився користуватися підзапитами, зв'язувати таблиці за допомогою
операторів типу `JOIN`, використовувати `CASE` для умовних переходів.
Також зрозумів, як можна вибирати дані за допомогою `UNION, INTERSECT + EXCEPT`
і розділяти таблиці горизонтально.

- Я навчився планувати події засобами `MySQL`, створювати
тригери, збереженні процедури та функції для зручнішої
взаємодії з базою даних. Також дізнався багато про
курсори, блокування та проведення трансакцій.

- Також я навчився базової оптимізації БД, і зрозумів, що важливо
правильно аналізувати потреби користувачів бази, і залежно від того,
що потрібно пришвидшити, вже можна створювати, чи навпаки прибирати
індекси, розділяти таблиці, використовувати змінні, щоб СКБД кешувала
запит, загалом писати більш ефективні запити, і цього я навчився в цій лабораторній  роботі.

### Актуальність бази

Якби мою базу потрібно було вже використати в реальному
магазині, то потрібно було б багато чого змінити
(хоча б через те, що в кожного магазину свої потреби в
даних), але загалом її вже можна використовувати.

# Бібліоґрафія
