def f23(x):
    tmpb = 1
    res = [[],[],[]]
    for i in range(len(x)):
        for j in range(len(x[i])):
            if j == 0:
                for k in range(len(x[i][j])):
                    if x[i][j][k] == ';':
                        tmp = x[i][j][:k:1]
                        x[i][j] = x[i][j][k + 1::1]
                        x[i][j + 1] = tmp
                        break
            if x[i][j] == 'true':
                if tmpb:
                    x[i][j] = '1'
                    tmpb = 0
            elif x[i][j] == 'false':
                if tmpb:
                    x[i][j] = '0'
                    tmpb = 0
        tmpb = 1
        if 'true' in x[i]:
            x[i].remove('true')
        if 'false' in x[i]:
            x[i].remove('false')
        x[i].remove(None)
    for i in range(len(x)):
        res[0].append(x[i][0])
        res[1].append(x[i][1])
        res[2].append(x[i][2])
    for i in range(len(res[0])):
        res[0][i] = res[0][i].replace('(', '')
        res[0][i] = res[0][i].replace(')', '')
        res[0][i] = res[0][i].replace(' ', '-')
        res[0][i] = res[0][i][:10:1] + res[0][i][11::1]
        res[1][i] = res[1][i].replace(' ', '.', 1)
        for j in range(len(res[1][i])):
            if res[1][i][j] == '.':
                res[1][i] = res[1][i][0] + res[1][i][j::]
                break
    return res
