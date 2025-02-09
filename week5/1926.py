# C++ 개긑은 컴파일 에러때매 파이썬으로 풀어봄

from collections import deque

# 도화지 크기, 색칠 정보 입력받기
n, m = map(int, input().split())
canvas = [list(map(int, input().split())) for _ in range(n)]

maxArea = 0
paints = 0

# 상, 하, 좌, 우 순서대로 이동
direction = [(-1, 0), (1, 0), (0, -1), (0, 1)]

for i in range(n):
  for j in range(m):
    # 방문한 적 있거나 색칠되지 않은 노드는 패스
    if canvas[i][j] == 0:
      continue
    
    # BFS 탐색 준비 (첫 노드 삽입)
    q = deque()
    q.append((i, j))
    area = 0
    canvas[i][j] = 0
    paints += 1

    # BFS
    while q:
      cur_x, cur_y = q.popleft()
      area += 1

      # 상하좌우 갈 곳 있는지 탐색
      for dx, dy in direction:
        next_x = cur_x + dx
        next_y = cur_y + dy

        # 범위를 벗어나거나, 방문했거나, 색칠되지 않은 곳이면 패스
        if next_x < 0 or next_x >= n or next_y < 0 or next_y >= m:
          continue
        elif canvas[next_x][next_y] == 0:
          continue
        
        # 탐색 대기
        q.append((next_x, next_y))
        canvas[next_x][next_y] = 0
    
    # BFS 끝나면 최대 넓이 업데이트
    maxArea = max(maxArea, area)

print(paints)
print(maxArea)