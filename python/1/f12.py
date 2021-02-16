#! usr/bin/python

def f(x):
    if x < -33:
        return x ** 6 - 20 * x ** 2  - 58
    elif -33 <= x <= 23:
        return (80 * x ** 2 + ln(x)) ** 2 + x ** 3
    else:
        return 19 * x ** 2 - x ** 4
