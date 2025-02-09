#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100001

vector<int> dist(MAX);

int main() {

  // 수빈이, 수빈이 동생 위치 입력 / dist 배열 초기화
  int x, k;
  cin >> x >> k;
  for (int i = 0; i < MAX; i++)
    dist[i] = -1;

  // BFS 루트 입력
  queue<int> q;
  q.push(x);
  dist[x] = 0;

  // BFS
  while(dist[k] < 0) {
    int cur = q.front();
    q.pop();

    // 이동할 수 있는 위치 (1칸 걷기, 2배 순간이동)
    int next[3] = {cur - 1, cur + 1, cur * 2};
    for (int i = 0; i < 3; i++) {
      int next_cur = next[i];

      // 이미 방문했거나 범위 벗어나는 경우 패스
      if (next_cur < 0 || next_cur >= MAX)
        continue;
      if (dist[next_cur] > -1)
        continue;

      // 다음 탐색 노드 입력하고 거리 계산
      q.push(next_cur);
      dist[next_cur] = dist[cur] + 1;
    }
  }

  cout << dist[k];

  return 0;
}