#include <iostream>
#include <queue>

#define X first
#define Y second
using namespace std;

int main() {

  int m, n;
  cin >> m >> n;

  queue<pair<int, int> > q;
  int maxDays = 0;

  // 토마토 정보 입력, 익은 토마토는 바로 BFS 루트 노드로 삽입
  int tomatos[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> tomatos[i][j];
      if (tomatos[i][j] == 1)
        q.push(make_pair(j, i));
    }
  }

  int dx[] = {0, 0, -1, 1};
  int dy[] = {-1, 1, 0, 0};
  
  // BFS
  while (!q.empty()) {
    int cur_x = q.front().X;
    int cur_y = q.front().Y;
    q.pop();

    // 상하좌우 순서대로 탐색
    for (int i = 0; i < 4; i++) {
      int next_x = cur_x + dx[i];
      int next_y = cur_y + dy[i];
      
      // 범위 초과하거나 이미 익었다면, 혹은 토마토가 없는 칸이라면 패스
      if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n)
        continue;
      if (tomatos[next_y][next_x] != 0)
        continue;
      
      // 방문 가능한 칸은 방문 대기
      q.push(make_pair(next_x, next_y));
      tomatos[next_y][next_x] = tomatos[cur_y][cur_x] + 1;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (tomatos[i][j] == 0) {
        cout << -1;
        return 0;
      }
      if (maxDays < tomatos[i][j])
        maxDays = tomatos[i][j];
    }
  }

  cout << maxDays - 1;

  return 0;
}