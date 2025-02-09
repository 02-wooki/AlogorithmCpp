#include <iostream>
#include <queue>

#define X first
#define Y second
using namespace std;

int main() {

  int n, m;
  cin >> n >> m;

  int arr[n][m];
  queue<pair<int, int> > q;

  // 미로 입력
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;

    // 0은 -1이 되고 1은 0이 됨 (-1이면 지나갈 수 없는 칸, 지나갈 수 있는 칸은 거리로 사용)
    for (int j = 0; j < m; j++)
      arr[i][j] = str[j] - '1';
  }

  int dx[4] = {0, 0, -1, 1};
  int dy[4] = {-1, 1, 0, 0};

  // BFS 첫 노드 입력
  q.push(make_pair(0, 0));
  arr[0][0] = 1;

  // BFS
  while (arr[n - 1][m - 1] <= 0) {
    int cur_x = q.front().X;
    int cur_y = q.front().Y;
    q.pop();

    for (int i = 0; i < 4; i++) {
      // 다음 갈 곳 (상하좌우) 좌표 구하기
      int next_x = cur_x + dx[i];
      int next_y = cur_y + dy[i];

      // 범위 초과하거나 이미 방문한 좌표이면 패스
      if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n)
        continue;
      if (arr[next_y][next_x] != 0)
        continue;

      // 방문 대기
      q.push(make_pair(next_x, next_y));
      arr[next_y][next_x] = arr[cur_y][cur_x] + 1;
    }
  }
  
  cout << arr[n - 1][m - 1];

  return 0;
}