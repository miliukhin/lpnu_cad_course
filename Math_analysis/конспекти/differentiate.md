$x^3$ has 3 identical perspectives.
When the system changes, all 3 perspectives contribute identically. Therefore, the derivative will be $3 * something$
.
The “something” is the change in one side ($dx$) multiplied by the remaining sides ($x*x$).
The changing side goes from $x$ to $dx$ and the exponent lowers by one.

$$
\frac{d}{dx}x^n = nx^{n-1}
$$

Now we can memorize the shortcut “bring down the exponent and subtract”, just like we know that putting a 0 after a number multiplies by 10. Shortcuts are fine once you know why they work!

# integrals of powers


Ok – we took the previous result and worked backward. But what about the integral of plain old $x^2$ ? Well, just imagine that incoming change is being split 3 ways:

$$
	x^2 = \frac{x^2}{3} + \frac{x^2}{3} + \frac{x^2}{3} = \frac{1}{3}3x^2
$$

Ah! Now we have 3 plates (each 1/3 of the original size) and we can integrate a smaller cube. Imagine the “incoming material” being split into 3 piles to build up the sides:

$$
	\int x^2 = \int \frac{1}{3} 3x^2 = \frac{1}{3} \int 3x^2 = \frac{1}{3} x^2
$$

If we have 3 piles of size
$x^2$
, we can make a full-sized cube. Otherwise, we build a mini-cube, 1/3 as large.

The general integration rule is:

$$
	\int x^n = \frac{1}{n + 1} x^{n+1}
$$

карче є куб із площею 2x^2, зміни кожної сторони --- 2x^2/3, тоді кубік буде 2/3 x^3

# The quotient rule

заміни $\frac{f}{g}$ на $a * b$ і подивися, що буде!

# https://betterexplained.com/calculus/lesson-15/ шось не те з $y = \sqrt{r^2 - x^2}$
# https://math.stackexchange.com/questions/335577/how-to-find-surface-area-of-a-sphere

We’re used to analyzing equations, but I hope it doesn’t stop there. Numbers can describe mood, spiciness, and customer satisfaction; step-by-step thinking can describe battle plans and psychological treatment. Equations and geometry are just nice starting points to analyze. Math isn’t about equations, and music isn’t about sheet music – they point to the idea inside the notation.

**Begin thinking about general patterns (x, x^2), not just specific shapes (a line, a square).**

$$
2x + dx \overset{dx = 0} \Longrightarrow 2x, \text{so} \frac{d}{dx} x^2 = 2x, \text{ with errors artifacts removed }
$$
