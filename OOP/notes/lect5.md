---
title: Обробка виняткових ситуацій (exception handling)
---

# Закінчите з плюсами --- переходите на джаву!

Виняткова ситуація ---

throw після перевірки помилки буде вказувати, що з нею робити

- функція визначає, що дійсно виникла умова виняткової ситуації;
- функція спроможна викликати одну, або декілька виняткових ситуацій різних
типів, використовуючи оператор throw, що відповідають різним умовам
виняткових ситуацій;
- як тільки оператор throw створює виняткову ситуацію, функція негайно
завершує своє виконання;
- надалі функція “робить запит” на розв’язування проблеми обробником
виняткової ситуації catch, що викликається автоматично на посилання об’єкта
виняткової ситуації.

**Closed.** This question needs [debugging details](/help/minimal-
reproducible-example). It is not currently accepting answers.

* * *

Edit the question to include [desired behavior, a specific problem or error,
and the shortest code necessary to reproduce the problem](/help/minimal-
reproducible-example). This will help others answer the question.

Closed 3 years ago.

[ Improve this question ](/posts/59518468/edit)

If argument doesn't fit to format, I want to throw message. I actually don't
know what happen. I tried to throw message with std::string but doesn't work.
What's going on there?

In addition, compiler gave "abort called" message.

I searched the topic before opening it, but I could not found a satisfactory
answer.



    string timeConversion(string s) {
        // hh:mm:ss:AM
        if(s.length() != 11)
            throw "message";

        return something;
    }


Edit: The code simplified.

  * [c++](/questions/tagged/c%2b%2b "show questions tagged 'c++'")

[Share](/q/59518468 "Short permalink to this question")

[Improve this question](/posts/59518468/edit)

Follow

[edited Dec 29, 2019 at 11:08](/posts/59518468/revisions "show all edits to
this post")

shalom

asked Dec 29, 2019 at 10:13

[![shalom's user
avatar](https://www.gravatar.com/avatar/d5a15f44a57125c5e3bef132321dea5a?s=64&d=identicon&r=PG&f=1)](/users/6074164/shalom)

[shalom](/users/6074164/shalom)shalom

19311 gold badge11 silver badge99 bronze badges

4

  * You should not throw build-in types, but instances of classes that ultimately inherit from `std::exception`. Either create your own class or [use one of the provided classes](https://en.cppreference.com/w/cpp/error/exception). Could you please elaborate a bit on your problem? The throw probably comes from your own code.

- [churill](/users/5105949/churill "11,108 reputation")

Dec 29, 2019 at 10:16

  * This code is about hackerrank. I am trying to solve a question. And I am writing a code in timeConversion() function.

- [shalom](/users/6074164/shalom "193 reputation")

Dec 29, 2019 at 10:21

  * 4

You are not throwing a `std::string`. You are throwing a pointer-decayed
string literal, i.e. a `const char*`. There is also no `catch` anywhere in the
shown code. What do you expect to happen?

- [walnut](/users/11941443/walnut "21,411 reputation")

Dec 29, 2019 at 10:21

  * @David I rewrote it slightly. I hope it doesn't sound sarcastic anymore. But that is a honest question. I don't know what OP is expecting the `throw` lines to do. Either they _did_ intend to throw a `std::string` and are catching it somewhere else (which they should show) or they actually just want to `return` or something completely different.

- [walnut](/users/11941443/walnut "21,411 reputation")

Dec 29, 2019 at 10:27

Add a comment  |

##  1 Answer 1

Sorted by:  [ Reset to default ](/questions/59518468/terminate-called-after-
throwing-an-instance-of-char-const-in-string-function?answertab=scoredesc#tab-
top)

Highest score (default)  Trending (recent votes count more)  Date modified
(newest first)  Date created (oldest first)

6

[](/posts/59518558/timeline "Show activity on this post.")

Don't throw strings (`const char*`):



    throw "failed because of hour";


make an exception `class`:



    class MyException : public std::exception
    {
    public:
        MyException(const char* err) : std::exception(err) {}
    };


and `throw` that:



    throw MyException("failed because of hour");


and then `catch` it:



    try
    {
        // code that might throw
    }
    catch(const MyException& ex)
    {
        // process exception
    }


if an exception is thrown and not caught (your current case) then `terminate`
is called.

[Share](/a/59518558 "Short permalink to this answer")

[Improve this answer](/posts/59518558/edit)

Follow

[edited Dec 29, 2019 at 11:27](/posts/59518558/revisions "show all edits to
this post")

answered Dec 29, 2019 at 10:26

[![Paul Evans's user
avatar](https://www.gravatar.com/avatar/5418f577abfa7c529dd026723462b440?s=64&d=identicon&r=PG)](/users/1312406/paul-
evans)

[Paul Evans](/users/1312406/paul-evans)Paul Evans

27.1k33 gold badges3636 silver badges5454 bronze badges

2

  * Thank you for answer. But I have to little change it. Because when I used to code, I received `No matching constructor for initialization of 'std::exception'`. Then I defined private string and used it instead of std::exception(err). Also I deleted `&` in constructor parameter because give me another errors. And then it worked.

- [shalom](/users/6074164/shalom "193 reputation")

Dec 29, 2019 at 11:03

  * 1

Sorry, forgot `std:: exception` takes a `const char*` editted answer. And your
totally welcome. :-)

- [Paul Evans](/users/1312406/paul-evans "27,136 reputation")

Dec 29, 2019 at 11:04

---

Виняткові ситуації відкидають необхідність резервування спеціальних
значень у помилкових ситуаціях. Якщо у програмі виникли необроблені
виняткові ситуації, то по замовчуванню викликається функція unexpected().
Найчастіше unexpected() викликає функцію terminate(), яка, в свою чергу,
викликає функцію abort() для аварійного завершення програми. Є можливість
замінити unexpected() та terminate() власними функціями-обробниками виняткових ситуацій.
