#include <iostream>
#include <utility>
#include <queue>

#define X first
#define Y second

using namespace std;

int main() {

  // 도화지 크기 입력받기
  int n, m;
  cin >> n >> m;

  // 색칠 정보 입력받기
  int canvas[n][m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> canvas[i][j];

  bool vis[n][m];

  // vis 배열 초기화
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      vis[i][j] = false;

  // 상, 하, 좌, 우 순서대로 이동
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};
  
  int maxArea = 0;
  int paints = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // 이미 방문한 노드이거나 색칠되지 않은 노드면 패스
      if (!canvas[i][j] || vis[i][j])
        continue;
      
      // 첫 노드 방문 준비
      queue< pair<int, int> > q;
      int area = 0; 
      
      q.push(make_pair(i, j));
      vis[i][j] = true;
      paints++;

      // BFS
      while (!q.empty()) {
        // 다음 방문할 노드 꺼내기
        int cur_x = q.front().X;
        int cur_y = q.front().Y;
        q.pop();

        area++;

        for (int k = 0; k < 4; k++) {
          // 상, 하, 좌, 우 순서대로 다음 방문할 수 있는 노드 계산
          int nextx = cur_x + dx[k];
          int nexty = cur_y + dy[k];

          // 범위를 벗어나거나, 색칠되어 있지 않거나, 이미 방문했으면 패스
          if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m)
            continue;
          else if (!canvas[nextx][nexty])
            continue;
          else if (vis[nextx][nexty])
            continue;
          
          // 방문해야 할 좌표에 대한 vis 업데이트하고 방문 대기열에 입력
          vis[nextx][nexty] = true;
          q.push(make_pair(nextx, nexty));
        }
      }

      // 최대 넓이 갱신
      if (maxArea < area)
        maxArea = area;
    }
  }

  cout << paints << '\n' << maxArea;

  return 0;
}