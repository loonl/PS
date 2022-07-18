import sys
from collections import deque
input = sys.stdin.readline

users, relations = map(int, input().split())
# make graph
graphs, bacon = [[] for _ in range(users)], 0
for i in range(relations):
    a, b = map(int, input().split())
    a, b = a - 1, b -1
    graphs[a].append(b)
    graphs[b].append(a)

# bfs
def bfs(num, target):
    global bacon
    temp_bacons = []
    if target in graphs[num]:
        return 1
    for next in graphs[num]:
        visited = [False for _ in range(users)]
        visited[num], temp_bacon = True, 1
        q = deque()
        q.append(next)
        while q:
            current = q.popleft()
            visited[current] = True
            temp_bacon += 1
            if target in graphs[current]:
                temp_bacons.append(temp_bacon)
                break
            for _next in graphs[current]:
                if not visited[_next]:
                    visited[_next] = True
                    q.append(_next)
    return min(temp_bacons)
# bfs main
bacons = []
for i in range(users):
    bacon = 0
    for j in range(users):
        if j != i:
            bacon += bfs(i, j)
    bacons.append(bacon)
print(bacons.index(min(bacons)) + 1)