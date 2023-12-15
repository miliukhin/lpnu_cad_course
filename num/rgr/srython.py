import math
def mainFunction(x):
    if x < 2:
        return 0
    else:
        return math.log(x)
x0 = 5
x4 = 10
h = (x4 - x0)/4
x_values = [0] * 5
y_values = [0] * 5
delta1 = [0] * 4
delta2 = [0] * 3
delta3 = [0] * 2
delta4 = [0]
delta = [delta1, delta2, delta3, delta4]
def factorial(number):
    if number == 1:
        return 1
    return number * factorial(number - 1)
def calculationX():
    global x_values, h, x0
    step = 0
    for i in range(5):
        x_values[i] = x0 + step
        step += h
def calculationY():
    global y_values, h, x0
    step = 0
    for i in range(5):
        y_values[i] = mainFunction(x0 + step)
        step += h
def calculationDeltas():
    calculationX()
    calculationY()
    global delta1, y_values, x_values
    for j in range(len(delta)):
        if j == 0:
             for l in range(len(delta[j])):
                k = 1 + j
                delta[j][l] = (y_values[l + 1] - y_values[l]) / (x_values[l + k] - x_values[l])
        else:
            for i in range(len(delta[j])):
                k = 1 + j
                delta[j][i] = (delta[j - 1][i + 1] - delta[j-1][i]) / (x_values[i + k] - x_values[i])
def functionY1(x_input):
    calculationDeltas()
    global delta, delta1, delta2, delta3, delta4, y_values, x_values, h
    y = 0.0
    y += y_values[0]
    for k in range(1, 5):
        sum = 0.0
        multiplication = 1.0
        for m in range(0, k):
            multiplication *= (x_input - x_values[m])
        sum = (delta[k - 1][0] / (factorial(k) * pow(h, k))) * multiplication
        y += sum
    return y
def functionY2(x_input):
    calculationDeltas()
    global delta, delta1, delta2, delta3, delta4, y_values, x_values, h
    y = 0.0
    y += y_values[4]
    for k in range(1, 5):
        sum = 0.0
        multiplication = 1.0
        for m in range(0, k):
            multiplication *= (x_input - x_values[4 - m])
        sum = (delta[k - 1][4 - k] / (factorial(k) * pow(h, k))) * multiplication
        y += sum
    return y
x = 9
print(f"[{x0}; {x4}]\nx = {x}\nf(x) = {mainFunction(x)}\np_1 = {functionY1(x)}\np_2 = {functionY2(x)}")
