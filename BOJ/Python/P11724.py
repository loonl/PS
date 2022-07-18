import sys
from collections import deque
input = sys.stdin.readline
n, m = map(int, input().split())
graphs, nums = [[] for _ in range(n)], [i for i in range(n)]

for _ in range(m):
    a, b = map(int, input().split())
    graphs[a-1].append(b-1)
    graphs[b-1].append(a-1)

# BFS
def bfs(num):
    visited, comp = [False for _ in range(n)], []
    q = deque()
    # insert first element in deque
    q.append(num)
    comp.append(num)
    visited[num] = True
    while q:
        current = q.popleft()
        for next in graphs[current]:
            if not visited[next]:
                comp.append(next)
                visited[next] = True
                q.append(next)
    return comp

# main part
finished, connected = [False for _ in range(n)], []
for i in nums:
    if finished[i]:
        continue
    temp = bfs(i)
    connected.append(temp)
    for j in temp:
        finished[j] = True

# final
print(len(connected))