from collections import deque
import sys

input = sys.stdin.readline

# read and make graph
n, m = map(int, input().split())
graph = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    graph[b-1].append(a-1)

# bfs
def bfs(x):
    q = deque()
    visited = [False for _ in range(n)]
    q.append(x)
    visited[x] = True
    count = 1
    while q:
        x = q.popleft()
        for next in graph[x]:
            if not visited[next]:
                count += 1
                visited[next] = True
                q.append(next)
    return count

# update answer with bfs
answer = [0 for _ in range(n)]
for i in range(n):
    answer[i] = bfs(i)

# print
for i in range(n):
    if answer[i] == max(answer):
        print(i+1, end=' ')