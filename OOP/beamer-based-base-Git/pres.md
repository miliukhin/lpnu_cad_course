---
title: Базована база Git
author: Олександр Мілюхін
institute: Національний університет "Львівська Політехніка"
aspectratio:
- 169
theme:
- Malmoe
---

### План

\tableofcontents

# Тупий відстежувач вмісту

### Git --- тупий відстежувач вмісту

На початках (1991–2002) зміни в ядро Linux передавалися як патчі та архіви. У 2002 р. проєкт
почав використовувати пропрієтарну РСКВ BitKeeper.

Git народилася у 2005, коли чувакам набридло миритися з комерційною натурою BitKeeper.

#### Чому **розподілена**?

бо, на відміну від старих централізованих систем,
розподілена система дає всім, хто завантажив репозиторій, можливість
перейти до будь-якого збереженого стану без звертання до сервера.

### Що можна відстежувати?

Все, що завгодно. Контроль версій може вам знадобитися
в місцях, де ви його найменше сподіваєтеся.

- програми
- конфігураційні файли
- документи (також вебсторінки)
- придумайте

Зміни в цій презентації також контрольовані за допомогою Git.

# Основи вжитку

## CLI

### CLI --- імба

Переваги використання Git через інтерфейс командного рядка:

\pause
- Ви не будете прив'язані до інтерфейсу якогось IDE
\pause
- Краще зрозумієте програму
\pause
- швидше будете знаходити рішення різних проблем
\pause
- будете виглядати як крутий гакер
\pause

#### Як не помилятися та швидше рухатись

\pause
- Натискати **`Tab`** (часом кілька разів) для автодоповнення
\pause
- **Стрілки** вгору-вниз для переміщення по історії команд
\pause
- *не вчити* команди, а **використовувати** їх

### Швидкий копен-дупен

#### Ініціалізація репо:

```sh
git init
git add .
git commit -m "мяу"
```
\pause

#### Повернення до початкового стану:

```sh
git reset --hard
```
\pause

#### Внесення нових змін:

```sh
git commit -a -m "якісь зміни"
```
> -a каже додати до індексу всі зміни/видалення

### bruh

\begin{columns}
\column{.5\textwidth}
\begin{figure}
	\includegraphics[width=.7\textwidth]{images/image_proxy.jpg}
\end{figure}
\end{columns}

### База

#### Додання
```sh
git add [назва-файлу]	# додати файл
```
\pause

#### Видалення

прибрати файл і з індексу git, і з файлової системи. `-r`, щоб рекурсивно:
```sh
git rm [назва-файлу]		# (remove)
git rm --cached назва-файлу	# видалити файл тільки з індексу
```
\pause

#### Перейменування

```sh
git mv bug.c feature.c	# фактично переміщення (move)
```

### Більше команд для відстежування

#### Історія

```sh
git log		# покаже список останніх комітів і їхні хеші SHA1
git reflog	# покаже зміни в гілках та посиланнях
```
\pause

#### Як просто повернутися?

Повернутися до потрібного коміту, створивши нову гілку:
```sh
git checkout [хеш-коміту] [додатково-перелік-файлів]
```
\vspace{5pt}
перейти на вказану гілку:
```sh
git checkout [назва-гілки]
```
\pause

#### Шо ви наробили коммітом?

```sh
git diff
```

## Сервери Git

### Самому сумно

Як працювати з іншими людьми? **Нам потрібен сервер!**

Ось кілька сервісів, що їх надають:

- [https://notabug.org/](https://notabug.org/)
- [https://github.com/](https://github.com/)
- [https://gitlab.com](https://gitlab.com)
- [https://sourceforge.net/](https://sourceforge.net/)

\pause

#### Або свій

Власний сервер Git запустити дуже просто,
наприклад, повторюючи команди з [цього посібника](https://landchad.net/git/).
Для вебінтерфейсу можна використати **cgit** або **gitea**,
про які там теж написано

### Під'єднання віддаленого сховища

#### Щоб пов'язати локальний репозиторій із сервером:

```sh
git remote add [назва-джерела] [ssh-або-https-адреса]
```

***Рекомендую ssh.***

\pause
#### Завантажити репо

```sh
git clone [ssh-або-https-адреса]
```

\pause
#### Завантажити зміни

```sh
git fetch [назва-джерела] [назва-гілки]	# просто інформація
git pull [назва-джерела] [назва-гілки]	# внесе локальні зміни
```

## Git у Visual Studio

### Час лізти в комп'ютер

\begin{columns}
\column{.6\textwidth}
\begin{figure}
	\includegraphics[width=\textwidth]{images/cat.jpg}
\end{figure}
\end{columns}

# Що далі?

### Веб

* [https://ohshitgit.com/](https://ohshitgit.com/) --- мінімалістичний сайт із рішеннями поширених проблем ([https://dangitgit.com/](https://dangitgit.com/) без матюків)
* !! [https://git-scm.com/docs](https://git-scm.com/docs) --- Документація на сайті Git
* [https://ndpsoftware.com/git-cheatsheet.html#loc=index;](https://ndpsoftware.com/git-cheatsheet.html#loc=index;) --- графічна шпаргалка
* [https://training.github.com/downloads/ua/github-git-cheat-sheet/](https://training.github.com/downloads/ua/github-git-cheat-sheet/) --- ше шпаргалка
* [http://www-cs-students.stanford.edu/~blynn/gitmagic/](http://www-cs-students.stanford.edu/~blynn/gitmagic/) --- гарна книжка
* [https://www.youtube.com/watch?v=mJ-qvsxPHpY](https://www.youtube.com/watch?v=mJ-qvsxPHpY) --- норм відео

### Більше книжок

\begin{columns}
	\column{.65\textwidth}
	\begin{enumerate}
		\item \textbf{Ben Lynn.} Магія Git
		\item \textbf{Scott Chacon, Ben Straub.} Pro Git
		\item \textbf{Ryan Hodson.} git succinctly
	\end{enumerate}
	\column{.35\textwidth}
	\begin{figure}
		\includegraphics[width=.6\textwidth]{images/image_proxy.png}
		\caption{книжка про Git}
	\end{figure}
\end{columns}

#### Або man-сторінки

зокрема gittutorial, giteveryday
