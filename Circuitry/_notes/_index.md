	інвертувати + переніс
SPST 1 перемикач
SPDT 2 перемикач
https://www.fpga.keoa.kpi.ua/fpga/cad-pld/functiona-logic-programming-lab-works/%D0%BB%D1%804-%D0%BF%D0%BE%D0%B1%D1%83%D0%B4%D0%BE%D0%B2%D0%B0-%D1%81%D1%85%D0%B5%D0%BC%D0%B8-%D0%B4%D0%B2%D1%96%D0%B9%D0%BA%D0%BE%D0%B2%D0%BE%D0%B3%D0%BE-%D1%81%D1%83%D0%BC%D0%B0%D1%82%D0%BE%D1%80.html

[counters](counters.md)
[lect3](lect3.md)
[тригери](lect4.md)
[регістри](lect5.md)
[notes](notes.md)
[shortcuts](shortcuts.md)
[дешифратори](дешифратори.md)
[sum](sum)
[chipset](chipset)
[memory](memory)
[prospects](prospects)

https://www.youtube.com/watch?v=PHG-PWPzizo change workspace size
https://www.youtube.com/watch?v=G0Yjl-KSHcQ logic expression
https://www.youtube.com/watch?v=mUyMjX4V7wc multiplexer simulation

суперскалярні

усі мікросхеми під'єднуються до шин паралельно

## шинні формувальники (кр580)

між шиною адрес мікропроцесора та шиною адресмікропроцесорної системи

- для буферизації шини адрес (2)
- n

## В основу побудови сучасних засобів обчислювальної техніки IV покоління покладені наступні принципи:

1) мікропрограмна організація керування;
2) модульний принцип побудови;
3) магістральний обмін інформацією;
4) регулярність структури.

У найпростіших компараторах на виході наявний
тільки сигнал, який інформує про рівність або нерівність кодів, тому такі
компаратори мають назву компаратори рівності  або нуль-органи.

## порівняння багаторозрядних

1. порівняти старші розряди (вони все визначають)
2. як рівні то йти до молодших

## переніс

По сути, просто разбитая функция преноса (единички) на более мелкие функции, которая в нашей голове автоматизированна. Видимо для электроники это необходимо. Пк же по рядам считает. Пренос исходящий - это перекинуть единичку, перенос входящий, забрать перекинутую единичку от предидущего столбца.
 На примере 10-тиричной системы 23+18 = 8+3 = 1 + пренос еденички (десятичной) + проверить перенос от предидущего столбца т.е  8+3+0: итого 1 и перенос <-1
следующий столбец 2+1+ проверить перенос от предидущего стобца т.е. 2+1+ 1<-  итого = 3 пренос 0 <-
следующий столбец какой будет.. о + о + пернесенный от предидущего столбца 0<- и так все 8 битных знаков.
 По-моему, все понятно

---

поріг переходу ближче до нуля в тих мікросхем (ТТЛ, МОН, ...),
тому краще тримати входи в одиниці мяу?