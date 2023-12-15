---
header-includes: \usepackage{graphicx}
---

# Radians

Sine is defined in terms of radians as

$$
sin(x) = x - \frac{x^3}{3!} + \frac{x^5}{5!} - \frac{x^7}{7!}
$$

This formula only works when x is in radians! Why? Well, sine is fundamentally related to distance moved, not head-tilting. But we’ll save that discussion for another day.


### "The wheels are turning 2000 degrees per second". You’d think:

> Ok, the wheels are going 2000 degrees per second. That means it’s turning 2000/360 or 5 and 5/9ths rotations per second. Circumference = 2 * pi * r, so it’s moving, um, 2 * 3.14 * 5 and 5/9ths… where’s my calculator…

### Ok. Now imagine a car with wheels of radius 2 meters (also a monster). “The car wheels are turning 6 radians per second”. You’d think:

> Radians are distance along a unit circle — we just scale by the real radius to see how far we’ve gone. 6 * 2 = 12 meters per second. Next question.

...
---

Radians to the rescue! Knowing they refer to distance traveled (they’re not just a ratio!), we can interpret the equation this way:

1. x is how far you traveled along a circle
2. sin(x) is how high on the circle you are

\begin{figure}[h]
\centering
\includegraphics[width=.6\textwidth]{sinx.png}
\caption{qwrou}
\end{figure}

When something moves a tiny amount, such as 0 to 1 degree from our perspective, it’s basically going straight up. If you go an even smaller amount, from 0 to .00001 degrees, it’s really going straight up. The distance traveled (x) is very close to the height (sin(x)).

As x shrinks, the ratio gets closer to 100% — more motion is straight up. Radians help us see, intuitively, why sin(x)/x approaches 1 as x gets tiny. We’re just nudging along a tiny amount in a vertical direction. By the way, this also explains why sin(x) ~ x for small numbers.

Sure, you can rigorously prove this using calculus, but the radian intuition helps you understand it.

Remember, these relationships only work when measuring angles with radians. With degrees, you’re comparing your height on a circle (sin(x)) with how far some observer tilted their head (x degrees), and it gets ugly fast.
