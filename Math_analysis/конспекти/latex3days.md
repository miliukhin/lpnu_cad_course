---
title: LaTeX за 3 дні
pdf-engine: pdflatex
header-includes:
- \input{~/Templates/lpnu_doc_templates/settings/preamble}
---

Математика
===

| 1                       | 2                        | 3                      |
| ---                     | ---                      | ---                    |
| $\int$ `\int`           | $\oint$  `oint`          |                        |
| $\sum$  `sum`           | $\prod$ `prod`           | $\coprod$ `coprod`     |
| $\bigcap$ `\bigcap`     | $\bigcup$ `bigcup`       | $\bigsqcup$ `bigsqcup` |
| $\bigoplus$ `\bigoplus` | $\bigotimes$ `bigotimes` | $\bigodot$ `bigodot`   |
| $\biguplus$ `\biguplus` | $\bigvee$ `bigvee`       | $\bigwedge$ `bigwedge` |

\begin{align}
	\int_a^b f(x) \, dx \\
	\oint_C a \; dr \\
	\sum_{i=0}^{n} q_i \\
	\bigcup_{-n \le k \le n} W_k \\
	\prod_{f \in F} f(x)
\end{align}

## Контроль розміщення меж

\begin{align}
	\int\limits_a^b f(x)\,dx \\
	\sum\nolimits_{i=0}^{n}q_i
\end{align}

## Кратні інтеграли

\begin{align}
	\iint, \iiint, \iiiint \\
	\iiint\limits_Vf(v)\,dv \\
	\idotsint_Vf(v)\,dv
\end{align}

## Частовикористовувані символи

|           |             |             |             |
| ---       | ---         | ---         | ---         |
| $\forall$ | $\exists$   | $\infty$    | $\mapsto$   |
| $\in$     | $\ni$       | $\emptyset$ | $\setminus$ |
| $\subset$ | $\supset$   | $\subseteq$ | $\supseteq$ |
| $\leq$    | $\geq$      | $\equiv$    | $\neq$      |
| $\cdot$   | $\approx$   | $\sim$      | $\cong$     |
| $\ll$     | $\gg$       | $\mid$      | $\neg$      |
| $\vee$    | $\wedge$    | $\lceil$    | $\rceil$    |
| $\perp$   | $\parallel$ | $\angle$    | $\triangle$ |
| $\lfloor$ | $\rfloor$   | $\partial$  | $\nabla$    |
| $\pm$     | $\mp$       | $\div$      | $\times$    |
| $\oplus$  | $\ominus$   | $\otimes$   | $\oslash$   |
| $\odot$   | $\cap$      | $\cup$      | $\circ$     |

## Стрілки

|                   |                       |
| ---               | ---                   |
| $\leftarrow$      | $\rightarrow$         |
| $\Leftarrow$      | $\Rightarrow$         |
| $\leftrightarrow$ | $\Leftrightarrow$     |
| $\longleftarrow$  | $\longrightarrow$     |
| $\Longleftarrow$  | $\longleftrightarrow$ |
| $\Longrightarrow$ | $\Longleftrightarrow$ |

$\Longrightarrow$ і $\Longleftrightarrow$ --- тоді й тільки тоді

### Визначення предела за Коші

$$
\forall \varepsilon>0 \quad \exists\delta(\varepsilon)>0
\; \colon \forall x \; 0<|x-a|<\delta \Rightarrow
|f(x)-b|<\varepsilon
$$

### Заперечення будь-якого символа --- `\not\символ`



| *          | *             | *        | *          |
| ---        | ---           | ---      | ---        |
| $\alpha$   | $\beta$       | $\gamma$ | $\delta$   |
| $\epsilon$ | $\varepsilon$ | $\zeta$  | $\eta$     |
| $\theta$   | $\vartheta$   | $\iota$  | $\kappa$   |
| $\lambda$  | $\mu$         | $\nu$    | $\xi$      |
| $\pi$      | $\varpi$      | $\rho$   | $\varrho$  |
| $\sigma$   | $\varsigma$   | $\tau$   | $\upsilon$ |
| $\phi$     | $\varphi$     | $\chi$   | $\psi$     |
| $\omega$   | $\Gamma$      | $\Delta$ | $\Theta$   |
| $\Lambda$  | $\Xi$         | $\Pi$    | $\Sigma$   |
| $\Upsilon$ | $\Phi$        | $\Psi$   | $\Omega$   |

\begin{align}
\mathcal{ABCDEFGHIJKLM} \\
\mathcal{NOPQRSTUVWXUZ} \\
\mathfrak{ABCDEFGHIJKLM} \\
\mathfrak{NOPQRSTUVWXUZ} \\
\mathfrak{abcdefghijklm} \\
\mathfrak{nopqrstuvwxuz} \\
\mathbb{ABCDEFGHIJKLM} \\
\mathbb{NOPQRSTUVWXUZ} \\
\end{align}

% каліграфічний
% готичний
% "ажурний" (Blackboard bold --- жирний шрифт для грифельної дошки)

***підрубай amsfonts***

книжка 4

## Акценти

$$
\hat x
\check x
\acute x
\grave x
\dot x
\ddot x
\dddot x
\ddddot x
\bar x
\vec x
\breve x
\tilde x
\mathring x
$$

\begin{multline}
i = 1, 2, \ldots, n \\
\sum_{i=1}^n a_i = a_1+a_2+\cdots+a_n \\
x_1+x_1x_2+ \cdots+x_1\ldots x_n
\end{multline}

`\vdots`, `\ddots` --- для матриць

## Дужки

\begin{align}
(x+y) \\
\langle x+y \rangle \\
[x+y] \\
\lfloor x+y \rfloor \\
\{x+y\} \\
\lceil x+y \rceil
\end{align}

$$
\bigl( \bigm| \bigr)
$$

Якщо треба просто збільшити символ --- `\big`

`\Big, \Bigl, \Bigm, \Bigr` у півтора рази більше, ніж `\big`
`\bigg, \biggl, \biggm \biggr` у два рази більше, ніж `\big`
`\Bigg, \Biggl, \Biggm \Biggr` 2.5 рази

$\left\{... \right..,$ коли треба тільки одну дужку

$$
\leqslant % отечествіний дарівнює
\geqslant
% \DeclareMathSymbol{\leqslant}{\mathrel}{AMSa}{"36}
% \DeclareMathSymbol{\geqslant}{\mathrel}{AMSa}{"3E}
% шоб не додавати весь amssymb
\lll
\ggg
\lessdot
\gtrdot
\fallingdotseq
\risingdotseq
\doteqdot
\vDash
\circlearrowleft
\curvearrowleft
$$

## Матриці

1. matrix --- просто вміст
2. pmatrix --- (.)
3. bmatrix --- [.]
4. vmatrix --- |.|
5. Vmatrix --- ||.||

`\setcounter{MaxMatrixCols}{20}`, бо максимальна --- 10.
Бажано повернути до 10 після набору великої матриці,
бо інакше \LaTeX$~$довше буде верстати.

`\(\left( \begin{smallmatrix} a & b \\ c & d \end{smallmatrix}
\right)\)`

$\left( \begin{smallmatrix} a & b \\ c & d \end{smallmatrix} \right)$

## Системи рівнянь та інші багатострокові конструкції

### Група формул із вирівнюванням

$$
\begin{aligned}
\sin x\pm\sin y& = 2\sin\frac{x\pm y}{2}\cos\frac{x\mp y}{2}\\
\sin x\sin y
& = \frac{1}{2}(\cos(x-y)-\cos(x+y))\\
\end{aligned}
$$

***& --- точка вирівнювання***

### Системи рівнянь

$$
\left\{\begin{aligned}
& x+y=5 \\ & x-2y=2
\end{aligned}\right.
$$

$$
\sqrt{f(x)}>g(x) \Longleftrightarrow
\left[ \begin{aligned}
& \left\{ \begin{aligned}
& f(x) > (g(x))^2 \\
& g(x) \ge 0
\end{aligned} \right. \\
& \left\{ \begin{aligned}
& f(x) \ge 0 \\
& g(x) < 0
\end{aligned} \right. \\
\end{aligned} \right.
$$

$$
\left|\begin{aligned}
& x < 5 \\ & x > 15
\end{aligned}\right.
$$

### Перерахування випадків

$$
|x| = \begin{cases}
x,
& x \ge 0, \\
-x, & x < 0
\end{cases}
$$

### Підписані знаки відношень

`\stackrel{...}{символ відношення}`

$\ln x\stackrel{\text{Df}}{=}y,\, e^y=x$

$\mathbb{R\times R} \stackrel{f(x,y)}{\longmapsto} \mathbb{R}$

$X \stackrel{\alpha} {\longrightarrow} Y$

#### Стрілки, що розтягуються
$f(x,y) \xrightarrow[D\rightarrow D_0] {(x,y)\in D} 0$

## Багатострокові індекси (`\substack`, `\subarray`)

\begin{equation}
	\lim_{\substack{
	x\rightarrow 0 \\
	y\rightarrow 0 \\
	z\rightarrow 0
	}} F(x,y,z)
\end{equation}

\begin{equation}
	\idotsint\limits_{
	\substack{x \in V\\
	\tau(x)>0}}
	\varphi\,ds
\end{equation}

#### Увага
Індекс потрібно брати в фігурні дужки

#### `\subarray{l}`
Робить те саме, вирівнявши індекси за лівим краєм

Титулка
===

## Центрування

\centerline{стрічка, розташована в центрі **смуги набору**}

\begin{centering}

... завжди відділяти, бо будуть глюки

\end{centering}

## Пропуски (горизонтальні, вертикальні)

---
10.7

---
