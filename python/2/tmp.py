def f23(x):
    for i in range(len(x)):
        x[i].remove(x[i][0])
        x[i].remove(x[i][2])
        for j in range(len(x[i])):
            if j == 0:
                x[i][j] = '(' + x[i][j][2::]
                x[i][j] = x[i][j][:4:] + ') ' + x[i][j][4:7:] + '-' + x[i][j][7::]
            if j == 1:
                if x[i][j] == 'Да':
                    x[i][j] = 'Выполнено'
                else:
                    x[i][j] = 'Не выполнено'
            if j == 2:
                x[i][j] = x[i][j].split(' ')[1] + ' ' + x[i][j].split(' ')[0]
    return x
print((f23([[None, '+71814553333', 'да', None, 'Гордей Гитян'], [None, '+78903799825', 'нет', None, 'Тамерлан Ленафко'], [None, '+74002248222', 'да', None, 'Павел Комов'], [None, '+79782045681', 'да', None, 'Радмир Тусушов']])))
