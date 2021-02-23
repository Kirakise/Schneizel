#! usr/bin/python
from math import *
def f14(x):
    if not(x):
        return 4
    else:
        return cos(f14(x - 1)) - f14(x - 1) ** 3 / 96
