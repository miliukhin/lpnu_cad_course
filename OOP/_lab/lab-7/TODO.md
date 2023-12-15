1
===

## Використовуючи АРІ-функції реалізувати наступні задачі для роботи з
процесами.

4. Запустити програму MSPowerPoint з високим пріоритетом. Завершити
виконання програми через 10 секунд.

## Використовуючи АРІ-функції реалізувати наступні задачі для роботи з потоками.

4. Написати програму для одночасного опрацювання масиву двома
потоками. Перший потік знаходитиме кількість елементів масиву в межах від 10
до 300, другий - середнє арифметичне парних елементів масиву.

2
===

## Використовуючи об’єкти синхронізації реалізувати наступні задачі для
роботи з потоками. Правильно розставити події для синхронізації потоків.
Порівняти результати з використанням синхронізації та без. Пояснити результат.

4. Написати програму для одночасного опрацювання матриці двома
потоками. Перший потік замінятиме кожен від’ємний елемент масиву на квадрат
цього елемента, другий - знаходитиме кількість рядків, у яких немає жодного
від’ємного елемента.

1. Що таке процес?
2. Яка АРІ-функція використовується для створення процесу?
3. Яка АРІ-функція використовується для завершення процесу?
4. Що таке потік?
5. Що таке синхронізація потоків?
6. Які є види синхронізації?
7. Які об’єкти використовуються для синхронізації потоків?
8. Що таке об’єкт синхронізації «подія»?

1. У комп'ютерних науках процес є екземпляром програми, який виконується на операційній системі і має власну адресний простір пам'яті, стек викликів, регістри та інші атрибути, що необхідні для його роботи.

2. Для створення процесу в операційній системі можна використати функцію API "CreateProcess" або її еквівалент у бібліотеці під назвою "fork" в UNIX-подібних операційних системах.

3. Для завершення процесу в операційній системі можна використати функцію API "ExitProcess" або її еквівалент у бібліотеці під назвою "exit" в UNIX-подібних операційних системах.

4. У комп'ютерних науках потік є послідовністю команд, яка виконується в межах процесу і має власний стек викликів та контекст виконання. Один процес може мати багато потоків, що дозволяє розділяти завдання між ними для досягнення кращої продуктивності.

5. Синхронізація потоків - це механізм, який дозволяє контролювати порядок виконання потоків, щоб уникнути проблем, таких як гонка за даними (race conditions) і блокування (deadlocks). Взаємодія між потоками може відбуватися через спільну пам'ять або через передачу повідомлень.

6. Види синхронізації:
- М’ютекс (mutex) - механізм, який дозволяє блокувати доступ до спільних ресурсів, щоб тільки один потік міг працювати з ними в один момент часу.
- Семафор (semaphore) - механізм, який дозволяє обмежувати кількість потоків, що можуть доступатися до спільного ресурсу одночасно.
- Умовна змі