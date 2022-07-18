import sys
import itertools
input = sys.stdin.readline

multi = [[1,1], [1,2,1], [1,3,3,1], [1,4,6,4,1],
         [1,5,10,10,5,1], [1,6,15,20,15,6,1],[1,7,21,35,35,21,7,1],
         [1,8,28,56,70,56,28,8,1],[1,9,36,84,126,126,84,36,9,1]]

def result(n, sum):
    if n == 1:
        print(1)
        return
    x, y = [i+1 for i in range(n)], multi[n-2]
    for a in itertools.permutations(x, n):
        hap = 0
        for j in range(n):
            hap += a[j] * y[j]
        if hap == sum:
            print(*a)
            return

n,sum = map(int, input().split())
result(n, sum)
