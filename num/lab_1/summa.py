#!/usr/bin/python
print("N S N*a D d")
def summa(a, n):
    s = 0
    for i in range(0, n):
        s += a
    na = n * a
    D = abs(na - s)
    d = 100 * D/na
    print(n, s, na, D, d)

a = float(input())
for m in range(100, 10000, 100): # крок 100
    summa(a, m)
