#! usr/bin/python
from math import *

def f(x):
    if not(x):
        return 4
    else:
        return cos(f(x - 1)) - f(x - 1) ** 3 / 96
