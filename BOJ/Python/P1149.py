import sys
input = sys.stdin.readline
n = int(input())
_a,_b,_c = [],[],[]

for _ in range(n):
    a,b,c = map(int, input().split())
    _a.append(a)
    _b.append(b)
    _c.append(c)

a, b, c = _a[0], _b[0], _c[0]
for i in range(1, n):
    __a = min(b, c) + _a[i]
    __b = min(a, c) + _b[i]
    __c = min(a, b) + _c[i]
    a,b,c = __a, __b, __c

print(min(a, b, c))