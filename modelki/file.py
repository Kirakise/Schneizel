#!/usr/bin/env python
from math import *

tabl = []
wes = []

def getsize(x, y):
    res = 1
    for i in x:
        if i > y:
            res += 1
    return res

print("Введите кол-во сравниваемых элементов")
a = int(input())
print("Введите кол-во критериев")
b = int(input())

tmp = []
for i in range(a):
    for j in range(b):
        print("Введите ", j + 1, " критерий для ", i + 1, "варианта")
        tmp.append(float(input()))
    tabl.append(tmp)
    tmp = []

print("Введите вес для каждого критерия")

for i in range(b):
    print("Введите вес для ", i + 1, " критерия")
    wes.append(float(input()))
kres = 0
for i in wes:
    kres += i

entr = []
vecmin = []
vecmax = []

for i in range(b):
    res = 0
    for j in range(a):
        res += tabl[j][i] * tabl[j][i]
    for j in range(a):
        tabl[j][i] = tabl[j][i] / sqrt(res)

for i in range(b):
    res = 0
    for j in range(a):
        if tabl[j][i] == 0:
            continue
        res += tabl[j][i] * log(tabl[j][i])
    entr.append(res * -1 / log(a))

for i in range(b):
    vecmax.append(-1)
    vecmin.append(2)
    for j in range(a):
        tabl[j][i] = tabl[j][i] * wes[i]
        if tabl[j][i] > vecmax[i]:
            vecmax[i] = tabl[j][i]
        if tabl[j][i] < vecmin[i]:
            vecmin[i] = tabl[j][i]

cof = []
for i in range(a):
    sm = 0
    sp = 0
    for j in range(b):
        sp += pow(vecmax[j] - tabl[i][j], 2)
        sm += pow(vecmin[j] - tabl[i][j], 2)
    sp = sqrt(sp)
    sm = sqrt(sm)
    cof.append(sm / (sp + sm))

for i in range(a):
    print("Вариант #", i + 1, "\tCi = ", cof[i], "\t", "Ранк:", getsize(cof, cof[i]))

