---
title: Первісна й інтеграл
author: книжка "Інтеграл"
pdf-engine: pdflatex
header-includes:
- \usepackage{amssymb}
- \usepackage{mathtools}
- \usepackage{polynom}
---

\twocolumn

> Читається цілий семестр на мехматі, я вам розкажу за три пари. --- **Пахолок Б. Б.**


Обернена до диференціювання операція інтегрування.
Інтегрування складніше за диференціювання. А ще інтеграл --- це греки.

Первісна
: функція $F(x)$ називається первісною (примітивною) для $f(x)$, якщо $F'(x) = f(x)$.

$$
f(x) = x, F(x) = \frac{x^2}{2} + 1, \text{~або~} \frac{x^2}{2} + c
$$

Теорема
: Якщо $F_1(x)$ і $F_2(x) \forall$ перв. для $f(x)$, то $F_1(x)-F_2(x)=c$

Отже, функція може мати безліч первісних.

# Питання

## Чи кожна функція f(x) має первісну?
$f(x)$ є неперервна $\to$ для неї існує первісна

> Диференціювання псує властивості функції, а інтегрування покращує.

## Чи первісна єдина (не єдина? тоді як знайти всі?)
$F(x) + c$

## Процес знаходження первісної

# Ньютон-Ляйбніц та всі їх учителі

Невизначений інтеграл
: множина всіх первісних функції

$$
\int f(x)\, dx = F(x) + c
$$

підінт. вираз:
$\begin{cases}
f(x) & \text{підінтегральна функція} \\
dx & \text{знак диференціяла}
\end{cases}$

#### !! Різниця з визначеним
невизначений не визначається однозначно, а з точністю до константи!!!

## 1. Таблиця інтегралів

<++>

## 2. Правила інтегрування

1. однорідність $$\int cf(x)\, dx = c \int f(x)\, dx$$
2. аддитивність $$\int \big( f(x) + g(x) \big) \, dx = \int(x)\, dx + \int g(x) \, dx$$

Ось комбінація цих правил: $$\int \big( \alpha f(x) + \beta g(x) \big) \, dx = \alpha\int f(x)\, dx + \beta\int g(x)\, dx$$

### Висновок

Операція інтегрування складніша

## Отрута та протиотрута
$$
\left( \int f(x)\, dx \right)' = f(x)
$$

> До речі, $\int f(x) \, dx = \int f(u) du = \text{нічо не змінює}$

# Методи обчислення

## 1. Безпосереднє інтегрування

Цей метод використовує таблицю, правила інтегрування та алгебраїчні властивості функцій. Все.

$$
\int(3x^3 + \sin x)\, dx = 3 \int x^3 + \int \sin x \, dx = \ldots 3\frac{x^4}{4} - \cos x + c
$$

[subs](https://tex.stackexchange.com/questions/274677/huge-braces-showing-integration-by-parts-calculus-on-the-middle-of-the-equatio)

\begin{equation}
	\int x^{\alpha}\, dx = \frac{x^{\alpha + 1}}{\alpha + 1} + c, \alpha \neq -1
\end{equation}

$df(x) = f'(x)\, dx$

\fbox{
$
d(\alpha x + b) = \alpha \, dx
$
}

$f(x) = g(x) \to f'(x) = g'(x)$

$$
\int f(x) \, dx = \int g(x) \, dx \text{~--- \bfseries з точністю до константи!!!}
$$

## 2. Метод підстановки і метод заміни змінної

> Якомога більше задач розв'язати, бо тут не все так просто

$$
\int(\alpha x + 1)^{10}\, dx
$$
Підстановка: \fbox{
$\begin{aligned}
	^{2x+1 = t}\\
	d(2x+1) = dt\\
	2\, dx = dt
\end{aligned}$
}
\begin{dmath}
\int t^{10} =
\frac{1}{2} \int t^{10}dt = \frac{1}{2} * \frac{t^{11}}{11} + c =
\frac{1}{22} (2x+1)^{11} +c
\end{dmath}

$$
\int \sin x \cos x \, dx = \int \underbrace{\sin x}_t  d\underbrace{\sin x}_t
$$
$$
= \int t dt = \frac{t^2}{2} + c =
\frac{1}{2} \sin^2 x + c
$$
\begin{multline}
\int \frac{2^x + 5^x}{10^x} =
\int (\frac{2^x}{10^x} + \frac{5^x}{10^x})\, dx =
\int (5^{\underbrace{-x}_{\displaystyle t}} + 2^{-x}\, \underbrace{dx}_{-dt} \\ =
% ] -x = t; \, dx = -dt [ =
-\int (5^t + 2^t)dt =
- \left( \int 5^tdt +\int 2^t dt \right)
\\ = \left( \frac{5^t}{ln 5} + \frac{2^t}{ln 2} \right) + c =
- \left(\frac{5^{-x}}{\ln 5} + \frac{2^{-x}}{\ln 2} \right) + c
\end{multline}

## 3. Інтегрування виразів із квадратними тричленами

$$
\int \frac{\, dx}{ax^2+bx+c}, \int\sqrt{ax^2+bx+c}\, dx, \int \frac{Ax +B}{ax^2+bx+c}
$$

тільки ***виділення повного квадрату:***
\begin{align}
\int \frac{\, dx}{x^2-4x+10} = \int \frac{d(x-2)}{(\underbrace{x-2}_{t})^2 +6}
% ] x-2 = t [
= \int \frac{dt}{t^2 +6} \\
= \int \frac{dt}{t^2 + (\sqrt{6})^2} =
\frac{1}{\sqrt{6}} \arctg \frac{1}{\sqrt{6}} + c
\end{align}

$$
	x^2 -4x + 10 = x^2 - 2*2x +4 + 6 = (x-2)^2 + 6
$$

є такий інтеграл
$$
	\int \frac{\, dx}{x^2+1} = \arctg x + c
$$

$$
	\int \frac{\, dx}{x^2 + 4^2} = 1/a \arctg \frac{x}{a}
$$

## 4. Формула інтегрування частинами

$$
	\int udv = uv - \int vdu
$$
\begin{gather*}
 	\int d (u \cdot v) = \int du \cdot v + \int u dv \\
 	u \cdot v = \int vdu + \int udv \\
 	\int udv = uv-\int vdu
\end{gather*}

 $$
 \int e^x * x \, dx = x * e^x - \int e^x \, dx = xe^x - e^x + c
 $$

 1. $e^x = u, x\, dx = dv, \to v = \frac{x^2}{2}$
 2. $e^x * x = u, \, dx = dv$
 3. $e^x\, dx = dv, x = u$ --- о!

**Який простіший?**

1. $\int \frac{x^2}{2} e^x \, dx$
2. ...
3. $v = e^x$ $$\int e^x\, dx = \int dv$$ Тут я не врахую константу: $e^x$

$\int e^x \, dx = \int dv$

### ...

Це тільки за тою формулою

$$
\int e^x * P_n(x) \, dx
$$

$P_n(x) = a_0x^n + a_1x^n-1 + ... + a_n$

$u = P_n(x),$
$dv = e^x \, dx$

### ...

1. $\int e^\alpha x * P_n (x) \, dx$ $u = P_n(x), dv = $
2. $\int a^{\alpha x} * p$

1. $\int P_n(x) \arctg \alpha x \, dx$. $u = \arctg \alpha x$, $dv = P_n(x)\, dx$
2. $\int P_n(x) \arcctg \alpha x \, dx$. $u = \arcctg \alpha x$
3. $\int P_n(x) \arcsin \alpha x \, dx$ $u = \arcsin \alpha x$
4. $\int P_n(x) \arccos \alpha x \, dx$ $u = \arccos \alpha x$

$\int sin (\ln x) \, dx$. $u = sin(\ln x), \, dx = dv$
$\int cos (\ln x) \, dx$. $u = cos(\ln x), \, dx = dv$

$\int e^{\alpha x} \cos \beta x \, dx$
$\int e^{\alpha x} \sin \beta x \, dx$
$\int a^{\alpha x} \cos \beta x \, dx$
$\int a^{\alpha x} \cos \beta x \, dx$

\begin{dmath}
\int e^{2x} \sin 3x \, dx \\
\Bigg] \begin{aligned}
e^{2x} = u \to du = 2e^{2x} \, dx; \\
\sin 3x\, dx = dv, \\
v = \frac{1}{3}\int \sin 3x d(3x) =
-\frac{1}{3} \cos 3x
\end{aligned} \Bigg[ \\
= e^{2x} * (-\frac{1}{3}\cos 3x + \frac{2}{3}\cos 3x * e^{2x}\, dx \\
\Bigg]
\begin{aligned}
e^2x = u; \\
\cos 3x\, dx = d; \\
v = \frac{1}{3} \sin 3x
\end{aligned}
\Bigg[ \\ = -\frac{e^{2x}}{3}\cos 3x + \frac{2}{3} \Big[ \frac{e^2x}{3} \sin 3x -\frac{2}{3} \int e^{2x} * \sin 3x\, dx \Big]
\\ = -\frac{e^{2x}}{3}\cos 3x + \frac{2}{9}e^{2x}sin3x
- \frac{4}{9}\int e^{2x} \sin 3x\, dx
\end{dmath}

$$
\frac{13}{9} \int e^{2x} \sin 3x\, dx = \frac{e^{2x}}{3}(2/3\sin 3x - cos 3x)
$$

$$
\frac{3}{13}(2/3 sin 3x - cos 3x) + c = \int e^{2x} \sin 3x \, dx
$$

## Вищий пілотаж (рекурентні формули) не даю

## Дробово-раціональні

завжди елементарні
$$
	\int \frac{a_0x^2 + a_1x^n-1 + ... + a_n}{b_0x^m + b_1x^{m-1} + ... + b_m}
$$

$$
\int e^{-x^2} \, dx \text{Пуасона}, \int \frac{\sin x}{x}\, dx \text{Їs}, \int \frac{\cos x}{x}\, dx
$$

ніяк елементарниим не виразиш

### 1. Якщо $n \geq  m$, то потрібно поділити чисельник на знаменник

$$
\int \frac{3x^2+2x-1}{x-3}\, dx = \int \left( 3x+11 + \frac{32}{x-3} \right) \, dx
$$

<++>

Якщо n < m, то не треба

### 2. Якщо $n <  m$, то

$$
\frac{1}{x-\alpha};
\frac{1}{(x-\alpha)^{\beta}};
\frac{Ax +B}{x^2 + px + q};
\frac{Ax +B}{(x^2 + px + q)^k}, k > 1
$$
