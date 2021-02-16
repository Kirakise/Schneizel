#! /usr/bin/python
from math import *
def f(x):
    res = 0

    for i in range(0, x + 1):
        res += i ** 6 + i ** 4 - 14
    return res
