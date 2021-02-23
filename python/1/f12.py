#! usr/bin/python
from math import *
def f12(x):
    if x < -33:
        return x ** 6 - 20 * x ** 2  - 58
    elif -33 <= x < 23:
        return (80 * x ** 2 + log(x)) ** 2 + x ** 3
    else:
        return 19 * x ** 2 - x ** 4
