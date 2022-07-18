n = int(input())
def recur(a):
    if len(a) < n:
        return recur(a+'0') + recur(a+'1') + recur(a+'2')
    elif len(a) == n:
        if int(a) % 3 == 0:
            return 1
        else:
            return 0
hap = recur('1') + recur('2')
print(hap)
