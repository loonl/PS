import sys
from collections import deque
input = sys.stdin.readline

# input
n,m,k = map(int, input().split())

# make graph
graphs, xys = [[] for _ in range(k)], []
for _ in range(k):
  y,x = map(int, input().split())
  y, x = n - y, x - 1 # 통상적인 x,y좌표로 변경
  xys.append((x,y))

for i in range(k):
  x,y = xys[i]
  temp_xys = xys[i:]
  up, down, left, right = (x, y+1), (x, y-1), (x-1, y), (x+1, y)
  if up in temp_xys:
    idx = xys.index(up)
    graphs[i].append(idx)
    graphs[idx].append(i)
  if down in temp_xys:
    idx = xys.index(down)
    graphs[i].append(idx)
    graphs[idx].append(i)
  if left in temp_xys:
    idx = xys.index(left)
    graphs[i].append(idx)
    graphs[idx].append(i)
  if right in temp_xys:
    idx = xys.index(right)
    graphs[i].append(idx)
    graphs[idx].append(i)

size = 0
# bfs
def bfs(num):
  global size, visited, skip
  q = deque()
  q.append(num)
  visited[num] = True
  while q:
    current = q.popleft()
    size += 1
    skip.append(current)
    for next in graphs[current]:
      if not visited[next]:
        visited[next] = True
        q.append(next)

# main
sizes, skip = [], []
for i in range(k):
  if i not in skip:
    size, visited = 0, [False for _ in range(k)]
    bfs(i)
    sizes.append(size)

print(max(sizes))