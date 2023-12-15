---
header-includes:
- \usepackage{multicol}
- \newcommand{\dx}{\hspace{2pt}dx}
- \newcommand{\dd}[1]{\hspace{2pt}d#1}
---

\begin{multicols}{2}

$$
\int x^n \dx = \frac{1}{n+1}x^{n+1}, \hspace{1ex} n\neq-1
$$

$$
\int \frac{1}{x}\dx = \ln |x|
$$

$$
\int u \hspace{2pt} \dd{v} = uv - \int v du
$$



$$
\int e^x \dx = e^x
$$

$$
\int a^x \dx = \frac{1}{\ln a} a^x
$$

$$
\int \ln x \dx = x \ln x - x
$$


$$
\int \sin x \dx = -\cos x
$$

$$
\int \cos x \dx = \sin x
$$

$$
\int \tan x \dx = \ln |\sec x|
$$

$$
\int \sec x \dx = \ln |\sec x + \tan x|
$$

$$
\int \sec^2 x \dx = \tan x
$$

$$
\int \sec x \tan x \dx = \sec x
$$

$$
\int \frac{a}{a^2+x^2}\dx = \tan^{-1}\frac{x}{a}
$$

$$
\int \frac{a}{a^2-x^2}\dx = \frac{1}{2}\ln\left|\frac{x+a}{x-a}\right|
$$

$$
\int \frac{1}{\sqrt{a^2-x^2}} \dx = \sin^{-1} \frac{x}{a}
$$

$$
\int \frac{a}{x \sqrt{x^2-a^2}} \dx = \sec^{-1} \frac{x}{a}
$$

\begin{align}
\int \frac{1}{\sqrt{x^2-a^2}} \dx &= \cosh^{-1} \frac{x}{a} \\&= \nonumber \ln (x+\sqrt{x^2-a^2})
\end{align}

\begin{align}
\int \frac{1}{\sqrt{x^2+a^2}} \dx &= \sinh^{-1} \frac{x}{a} \\&=\nonumber \ln (x+\sqrt{x^2+a^2})
\end{align}

\end{multicols}
