---
title: яка тема
author: Пахолок Б. Б.
header-includes:
- \usepackage{amssymb}
- \usepackage{mathtools}
- \usepackage{polynom}
---

> я припиняю доведення великої теореми Ферма, бо небеса на мене розгнівалися --- *дядько*

$$
	\int \frac{ 3x^2 + x + 3 }{ (x-1)^2(x^2 + 1) } \, dx \\
	= \frac{7}{2} \int \frac{dx}{(x-1)^2 } - \frac{1}{2} \int \frac{dx}{x^2 + 1}
	= -\frac{7}{2} \frac{1}{x-1} - \frac{1}{2}\arctg x + c
$$
$$
	\frac{ 3x^2 + x + 3 }{ (x-1)^2(x^2 + 1) } =
	\frac{A}{x-1} + \frac{B}{(x-1)^2 } + \frac{Cx + D}{ x^2 + 1 } =
	\frac{ 7/2 і т д}{}
$$

Метод невизначених коефіцієнтів:

\begin{dmath}
	3x^2 + x + 3 = A(x-1)(x^2 + 1) + B (x^2 + 1) + (Cx + D)(x^2 - 2x + 1) \\
	3x^2 + x + 3 = A(x3 - x^2 + x - 1) + B (x^2 + 1) + (Cx^3 -2cx^2 - cx + Dx^2 - 2Dx + D \\
	??x^3 : D = A + C
\end{dmath}


<++> система

> Шось інше крім многочлена, дробораца, нат лог і арктангенса? ФІГНЯ!!!

# Інтегрування ірраціональних функцій

\begin{dmath}
\int \frac{dx}{ \sqrt[3]{x^2} + \sqrt{x} } =
\\
]
x = t^6 (спільзнам знаменників) \\
dx = 6t^5 dt
\sqrt[3]{x^2}=t^4
\sqrt[3]{x}=t^3
[
\\ % раціоналізація інтегралу
= \int \frac{ 6t^5 \, dt}{t^4 + t^3} = 6 \int \frac{t^2 dt}{t+1} \\
= 6 \int (t-1 + \frac{1}{t + 1}) dt = 6(\frac{t^2}{2} -t + \ln |t+1|) + c
= 6 (\frac{ \sqrt[3]{x} }{2} - \sqrt[6]{x} + \ln  | \sqrt[6]{x} + 1 | ) - c
\end{dmath}

\begin{dmath}
	\frac{\sqrt{x-1}}{}
\end{dmath}

burhhhhhhhhhhhhhhhhhhhhhhhhhh....

# Інтегрування тригонометричних функцій

\begin{dmath}
	\int R (\sin x, \cos x) \, dx
\end{dmath} R - поліном якйсь

#### Універсальна тригонометрична підстановка: $tg \frac{x}{2} = t$
За її допомогою таке можна проінтегрувати

\begin{dmath}
	x = 2\arctg t
	dx = \frac{2dt}{1+t^2}
\end{dmath}

$$
\sin x = \frac { \sin 2\frac{x}{2} }{sin^2 \frac{x}{2} + \cos^2 \frac{x}{2}}
= \frac{ 2\tg \frac{x}{2} }{\sin^2 \frac{x}{2} + \cos^2 \frac{x}{2} = \frac{2t}{t^2+1}}
\cos x = \frac{ ...}{}
$$
