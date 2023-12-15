import numpy as np
A =[[14.0, -4.0, 2.0, 6.0],
    [-1.0, 15.0, -1.0, 8.0],
    [2.0, -3.0, 11.0, -2.0],
    [1.0, 6.0, 4.0, 15.0]]
b = [10.0, -6.0, -8.0, -5.0]
x0 = [0.0, 0.0, 0.0, 0.0]
def gaus(A, b):
    y = [0.0, 0.0, 0.0, 0.0]
    x = [0.0, 0.0, 0.0, 0.0]
    c = np.zeros((len(A), len(A)))
    d = np.zeros((len(A), len(A)))
    def gausC(ic, jc):
        sum_ = 0.0
        for j in range(0, jc):
            sum_ += c[ic][j] * d[j][jc]
        return sum_
    def gausD(ic, jc):
        sum = 0.0
        for i in range(0, ic):
            sum += c[ic][i] * d[i][jc]
        return sum
    def gausY(ic):
        sum = 0.0
        for i in range(0, ic):
            sum += c[ic][i] * y[i]
        return sum
    def gausX(ic):
        sum = 0.0
        for i in range(ic, len(A)):
            sum += d[ic][i] * x[i]
        return sum
    for i in range(0, len(A)):
        c[i][0] = A[i][0]
        d[i][i] = 1
        d[0][i] = A[0][i] / c[0][0]
    for k in range(2, len(A) + 1):
        for j in range(1, k):
            for i in range(j, len(A)):
                c[i][j] = A[i][j] - gausC(i, j)
        for i in range(1, k):
            for j in range(i + 1, len(A)):
                d[i][j] = (1 / c[i][i]) * (A[i][j] - gausD(i,
j))
    for k in range(0, len(y)):
        y[k] = ( b[k] - gausY(k)) / c[k][k]
    k = len(x) - 1
    i = 0
    while k >= 0:
        x[k] = y[k] - gausX(k)
        k -= 1
    return x
def seidel(A, b, x0,  max_iter=2):
    x = x0
    R = np.column_stack((np.array(A), np.array(b)))
    col = 5
    row = 4
    for i in range(0, row):
        ele = R[i][i]
        for j in range(0, col):
            if(j == i or j == (col - 1)):
                R[i][j] = R[i][j] / ele
            else:
                R[i][j] = -(R[i][j] / ele)
    x[0] = R[0][4]
    x[1] = R[1][4]
    x[2] = R[2][4]
    x[3] = R[3][4]
    for k in range(0, max_iter + 1):
        x_val = 0.0
        for i in range(0, row):
            for j in range(0, col):
                if(i == j):
                    continue
                elif(j == col - 1):
                    x_val += R[i][j]
                else:
                    x_val += R[i][j] * x[j]
            x[i] = x_val
            x_val = 0.0
    return x
solution = seidel(A, b, x0)
print("Seidel:", solution)
print()
solution = gaus(A, b)
print("Gauss:", solution)
