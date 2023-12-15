---
pdfengine: pdflatex
---

\twocolumn

# Числові ряди

\begin{equation}
a_1, a_2, a_3, ..., a_n ...
\label{a_ser}
\end{equation}
\begin{equation}
a_1 + a_2 + a_3 + ... + a_n ... = \sum_{n=1}^\infty
\end{equation}
$a_n$ --- $n$-й член ряду,
загальний член ряду

$$
	1, \frac{1}{2}, \frac{1}{2^2}, \dots; q = \frac{1}{2}
$$
$$
1 + \frac{1}{2} + \frac{1}{2^3} + \cdots + \frac{1}{n} + ...
= \frac{1}{1-q} = \frac{1}{1-\frac{1}{2}} = 2
$$
\begin{align*}
S_1 = a_1 \\
S_2 = a_1 + a_2 \\
%% S_3 = a_1 + a_2 + a_3 \\
S_n = a_1 + a_2 + \cdots + a_n
\end{align*}
$S_1, S_2, s_3, ..., s_n, ...$ послідовність частинних сум
$$
	\lim_{n\to\infty} S_n = S
$$
Сума ряду --- границя послідовності його частинних сум.

$S<\infty$
: ряд збіжний

$S = \infty$ або $\lim_{n\to\infty} S_n$ не існує
: розбіжний

$1 + \frac{1}{2} + \frac{1}{2^3} + \cdots + \frac{1}{n} + ...
= \frac{1}{1-q} = \frac{1}{1-1/2} = 2$ Збіжний
$$
S_n = 1 + 2 + 3 + \cdots + n = \frac{n(n+1)}{2}
$$
$$
\lim_{n\to\infty} S_n =
\lim_{n\to\infty} \frac{n(n+1)}{2} = \infty
$$

$$
1-1+1-1+
1-1+1-1+... = S
$$
$$
S_1 = 1, s_2 = 0 \text{~і т.д.}
$$
границі не існує, але Ейлер думав шо це 1/2, і
так доводив:
\begin{align}
	1-(\underbrace{1-1+1-1+...}_S) = S \\
	1-S = S \\
	1 = 2S \\
	S = \frac{1}{2} \text{~хуліганство}
\end{align}

## Необхідна Умова збіжності ряду

Ящо ряд (\ref{a_ser}) збіжний, то $\lim_{n\to\infty} a_n = 0$.
$$
	\text{Тому~} 1 + \frac{1}{2} + \frac{1}{3} +\cdots +\underbrace{\frac{1}{n}}_{a_n} + \cdots \text{~збіжний}
$$
Але вона недостатня

## Ознаки порівняння (для рядів із додатними членами)

#### Т. 1
Нехай задано два ряди:
	\begin{equation}
	a_1, a_2, a_3, ..., a_n ... \label{a}
	\end{equation}
	\begin{equation}
	b_1, b_2, b_3, ..., b_n ... \label{b}
	\end{equation}
$\forall n \in N : a_n \leq b_n$

Тоді
: зі збіжності ряду \ref{b} $\implies$ збіжність ряду \ref{a}
: з розбіжності ряду \ref{a} $\implies$ розбіжність ряду \ref{b}

#### Т. 2
Нехай $\exists \lim_{n\to\infty} \frac{a_n}{b_n} = k \neq 0$,
	тоді ряди 1 і 2 збігаються або розбігаються одночасно

### 1. Ознака д'Аламбера (гранична)

Нехай $q = \lim_{n\to\infty} \frac{a_{n+1}}{a_n}$, \underline{$0<q<1$}

Тоді
: $q < 1 \implies$ ряд збіжний
: $q > 1 \implies$ ряд розбіжний
: $q = 1 \implies$ ???

### 2. Радикальна ознака Коші

$$
q = \lim_{n\to\infty} \sqrt[n]{a_n}
$$

Тоді
: $q < 1 \implies$ ряд збіжний
: $q > 1 \implies$ ряд розбіжний
: $q = 1 \implies$ ???

### 3. Інтегральна ознака Маклорена-Коші

Нехай $\exists f(x)$ така, що $f(n) = a_n$

Нехай $\int_1^\infty f(x)dx$ (невл інт 1 роду)
: збіжний, то ряд збіжний.
: Якщо інтеграл розбіжний, то й ряд розбіжний.

$$
	1 + \frac{1}{2} + \frac{1}{3} +\cdots +\underbrace{\frac{1}{n}}_{a_n} + ...
$$
$$
	\lim \frac{a_{n+1}}{a_n} = \lim \frac{n}{n+1} = 1
$$
$$
	\lim \sqrt[n]{\frac{1}{n}} = \frac{1}{\sqrt[n]{n}} = 1
$$
Коротше, 1 і 2 лохи, інтегральна ознака дає змогу зрозуміти все
чітко:
$$
f(x) = 1/x, f(n) = 1/n
$$
$$
	\int_a^\infty \frac{1}{x} dx = \lim_{A\to\infty} \int_1^A \frac{dx}{x} = \lim_{A\to\infty}\ln x \big|_1^a = \lim_{A\to\infty}\ln A - 0 = \fbox{$\infty$}
$$

$\frac{a + b}{2}$
: сер ариф

$\sqrt{ab}$
: сер. геометричне

$\frac{2}{\frac{1}{a} + \frac{1}{b}}$
: середнє гармонічне

	$$
	1 + \frac{1}{2} + \frac{1}{3} +\cdots + \frac{1}{n-1} + \frac{1}{n} + \cdots
	$$

$$
	\frac{2}{ \frac{1}{n-1} + \frac{n}{n+1}} = \frac{2}{n-1+n+1} = \frac{2}{2n} = \frac{1}{n}
$$

$$
1 + \frac{1}{2^\alpha} + \frac{1}{3^\alpha} + \cdots + \frac{1}{n^\alpha} + \cdots
$$

$$
	\int_1^\infty \frac{dx}{x^\alpha}
$$

### дослідити на збіжність

$$
\sum_{n=1}^{\infty} \frac{n!}{(2n-1)!}
$$

$$
	a_{n} = \frac{n!}{(2n-1)!}
	a_{n+1} = \frac{(n+1)!}{(2n+1)!}
$$
$$
	q = \lim \frac{a_n+1}{a_n} =
	\lim \frac{(n+1)! (2n-1)!}{(2n+1)! n!} = 0
$$
Збіжний

# Функціональні ряди

\begin{equation}
u_1(x) +
u_2(x) +
\cdots +
u_n(x) +
\cdots, x\in D
\label{func}
\end{equation} 3-func, 4-func_x
\begin{equation}
u_1(x_0) + u_2(x_0) + \cdots + u_n(x_0) + \cdots \text{--- числовий}
\label{func_x}
\end{equation}

Областю збіжності ряду (\ref{func}) називається множина $x$ із $D$,
для яких він збіжний
$$
|u_1(x)| +
|u_2(x)| +
\cdots +
|u_n(x)| +
\cdots, x\in D
$$
$u_n(x) \leq |u_n(x)|$
$$
	q = \lim_{n\to\infty} \left| \frac{u_{n+1}(x)}{u_n(x)} \right| < 1
$$
$$
	\sum_{n=1}^\infty \ln^n x = \ln x + \ln^2 x + \ln^3 x + ...
$$
 ?? x > 0
$$
	q = \lim_{n\to\infty} \left| \frac{\ln^{n+1}(x)}{\ln^n(x)} \right| = \lim | \ln x | = |\ln x | < 1
$$
$$
	-1 < \ln x < 1
$$
$$
	\ln e^{-1} < \ln x < \ln e
$$
$$
	\frac{1}{e} < x < e
$$
$$
	\ln e +
	\ln^2 e +
	\ln^3 e +
	\text{n-й член не прямує до 0, незбіжний}
$$

$$
u_1(x) + u_2(x) + \cdots + u_n(x) ... = S(x)
$$
\begin{align}
1 + x + x^2 ... = \frac{1}{1-x} \\
|x|<1 \\
1, x, x^2
\end{align}

### Велика математична філософія

Всі мають похідні (неперервні), а чи має сума?
А інтеграл чи сума має?
Тобто чи має сума ряду властивості елементів?

> *Блін! Може ви собі почитаєте там*

##### Теорема Вейєрштрасса (19 ст)

Якщо
$\forall n \in N : |u_n(x)| < a_n$ і ряд $a_1+a_2+ ...$ збіжний, то ряд (\ref{func}) збігається абсолютно й рівномірно (усі властивості зберігаються)
\begin{align}
	1-x^2+x^4-x^6 + \cdots \\
	|x|<1, q = -x^2 \\
	1-x^2+x^4-x^6 \cdots = \frac{1}{1+x^2}
\end{align}
Кожен член має первісну! проінтегрую
$$
	\int_0^y (1-x^2+x^4-x^6 + \cdots) dx
	= \int_0^y \frac{1}{1+x^2} dx
$$
$$
	y-\frac{y^3}{3}+
	\frac{y^5}{5}-
	\frac{y^7}{7}+ = \arctg y
$$

за значення $y = 1$ ряд збіжний

$$
	1 - \frac{1}{3} + \frac{1}{5} - \frac{1}{7} + \cdots
	= \frac{\pi}{4} \text{гм, пі}
$$

# Знакозмінні ряди

\begin{equation}
	a_1+a_2+a_3+\cdots+a_n+\cdots
	\label{pm}
\end{equation}
$$
	1 + \frac{1}{2} - \frac{1}{3} + \frac{1}{4} +\frac{1}{5} +\frac{1}{6} -\frac{1}{7}
$$

Знакочерговий
: $1-1+1-1+ 1-1+1-1+... = S$

\begin{equation}
	|a_1|+|a_2|+|a_3|+\cdots+|a_n|+\cdots
	\label{abs}
\end{equation}

#### Знакозмінний ряд (\ref{pm}):
абсолютно збіжний
: збігається ряд (\ref{abs}) із модулів його членів

Умовно (неабсолютно) збіжний
: ряд (\ref{abs}) із модулів розбіжний, а сам він збіжний

#### Т. Ляйбніца

Нехай ряд (\ref{pm}) знакочерговий, $\forall n, |a_n| \geq |a_{n+1}|$,
$\lim_{n\to\infty} a_n = 0$ $\implies$ ряд (\ref{pm}) збіжний, та не абсолютно?

$$
a + b = b + a?
$$
Якщо ряд абсолютно збіжний, то та! Але якщо ні, то то болото,
там чорти водяться

#### Т. Рімана
Якщо ряд збіжний умовно, то в ньому можна так переставити члени,
що він буде збігатися до наперед заданого дійсного числа. Також можна так переставити, шо він розбіжиться.

# Степеневі ряди

$$
	a_0 + a_1x + a_2x^2 + \cdots + a_nx^n
$$
$a_n$ --- коефіцієнти степеневого ряду

#### Т. Абеля [^sho]
Якщо ряд збіжний при $x=x_0$, він буде збіжний і для
$\forall x : |x| < |x_0|$

розбіжний при $x=x_1$, то
$\forall x : |x| > |x_1|$

[^sho]: Що ви знаєте про математиків? Стефан Банах функціональний аналіз надумав

$$
1+x+x^2+x^3+\cdots+x^n+\cdots = \frac{1}{1-x}
$$
Так де Ейлер помилився? на вулиці зупините, поставлю плюс

### Радіус збіжності

$$
R = \lim_{n\to\infty} |\frac{a_n}{a_{n+1}} = \frac{1}{\lim_{n\to\infty} \sqrt[n]{|a_n|}}
$$
$$
	\sum \frac{1}{\sqrt[3]{n}}
	\left( \frac{x}{5} \right)^n
	= \sum \frac{x^n}{\sqrt[3]{<++>}}
$$
$$
	a_n = \frac{1}{\sqrt[3]{n} 5^n}
	R = \frac{1}{\lim \sqrt[n]{\sqrt[3]n * 5^n} }
	= \frac{1}{5\lim \sqrt[3n]{n}  }
	\frac{1}{lim \sqrt[n]{1/}} = 5
$$
$$
	\sum \frac{1}{\sqrt[3]{n}} = \sum \frac{1}{n^{1/3}}
$$
