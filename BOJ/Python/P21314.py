a=list(str(input()))
num, _max, _min, tmp = 0, "", "", ""
for i in range(len(a)): #min
    if a[i] == 'M':
        num += 1
        tmp = tmp + '1' if tmp == "" else tmp + '0'
        _min = _min + tmp if i == len(a) - 1 else _min
    elif a[i] == 'K':
        if num != 0:
            _min += tmp
            tmp, num = '', 0
        _min += '5'
tmp, num = "", 0
for i in range(len(a)): # max
    if a[i] == 'M':
        num += 1
        tmp = tmp + '1'
        _max = _max + tmp if i == len(a) - 1 else _max
    if a[i] == 'K':
        if num != 0:
            _max += '5'
            for j in range(num):
                _max += '0'
            num, tmp = 0, ''
        elif num == 0:
            _max += '5'
print(_max)
print(_min)
