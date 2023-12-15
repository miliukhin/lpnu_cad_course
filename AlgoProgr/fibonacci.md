0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

$F_0 = 0, F_1 = 1$
$F_{n+1} = F_n + F_{n-1}, n \in N$

if (n == 0)
	return 0;
else if (n == 1)
	return 1;
else
	return yuuuuuuuuuuuushchenkooooooooooo_tak;

Час роботи алгоритму експоненційний
$T(n) >= F_n!$

# fib2

```
if (n == 0)
	return 0;

створити масив f [0:n]
f[0] = 0, f[1] = 1;

for (int i = 2; i < n; i++)
	f[i] = f[i-1] + f[i-2];

return f[n]
```
