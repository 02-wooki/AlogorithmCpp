#include <iostream>
#include <queue>
using namespace std;

int main() {

  int r, c;
  cin >> r >> c;

  queue<pair<int, int> > jihun;
  queue<pair<int, int> > fire;

  // 미로 입력
  int arr[r][c];
  for (int i = 0; i < r; i++) {
    string str;
    cin >> str;

    // .(지훈이 이동할 수 있는 공간)은 0
    // J(지훈의 초기 위치)는 1
    // F와 #(이동할 수 없는 공간)은 -1로 입력
    for (int j = 0; j < c; j++) {
      arr[i][j] = str[j];
      if (arr[i][j] == 'J') {
        jihun.push(make_pair(j, i));
        arr[i][j] = 1;
      }
      else if (arr[i][j] == 'F') {
        fire.push(make_pair(j, i));
        arr[i][j] = -1;
      } else if (arr[i][j] == '#') {
        arr[i][j] = -1;
      } else {
        arr[i][j] = 0;
      }
    }
  }

  int dx[] = {0, 0, -1, 1};
  int dy[] = {-1, 1, 0, 0};
  int curTime = 0;

  // BFS
  while (!jihun.empty()) {
    int fireSize = fire.size();
    int jihunSize = jihun.size();
    curTime++;

    // 불이 번지는 모든 경로 탐색
    while (fireSize--) {
      int cur_x = fire.front().first;
      int cur_y = fire.front().second;
      fire.pop();

      // 불 번질 곳 탐색
      for (int i = 0; i < 4; i++) {
        int next_x = cur_x + dx[i];
        int next_y = cur_y + dy[i];

        // 범위를 초과하거나, 벽이거나, 이미 방문한 곳이면 패스
        if (next_x < 0 || next_x >= c || next_y < 0 || next_y >= r)
          continue;
        if (arr[next_y][next_x] < 0)
          continue;

        // 다음 갈 곳 대기열에 넣고 불났다 표시하기
        fire.push(make_pair(next_x, next_y));
        arr[next_y][next_x] = -1;
      }
    }

    // 지훈이 이동 가능한 모든 경로 탐색
    while (jihunSize--) {
      int cur_x = jihun.front().first;
      int cur_y = jihun.front().second;
      jihun.pop();

      // 지훈 도망갈 곳 탐색
      for (int i = 0; i < 4; i++) {
        int next_x = cur_x + dx[i];
        int next_y = cur_y + dy[i];

        // 범위 초과하면 탈출 성공
        if (next_x < 0 || next_x >= c || next_y < 0 || next_y >= r) {
          cout << curTime;
          return 0;
        }
        // 벽이거나, 불이거나, 이미 방문한 곳이면 패스
        if (arr[next_y][next_x] != 0)
          continue;

        // 다음 갈 곳 대기열에 넣고 방문 표시
        jihun.push(make_pair(next_x, next_y));
        arr[next_y][next_x] = 1;
      }
    }
  }

  // 지훈이가 탈출하지 않았는데 갈 곳이 없으면 탈출 불가능
  cout << "IMPOSSIBLE";

  return 0;
}