#include <iostream>
#include <deque>
using namespace std;

int main() {

  int n, m, cnt = 0;
  cin >> n >> m;

  deque<int> q;
  for (int i = 0; i < n; i++)
    q.push_back(i + 1);

  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;

    // 값 위치 찾기
    int idx;
    for (int j = 0; j < q.size(); j++) {
      if (q[j] == x) {
        idx = j;
        break;
      }
    }

    // 큐 돌리기
    while (q.front() != x) {
      if (idx * 2 < q.size()) {
        q.push_back(q.front());
        q.pop_front();
      } else {
        q.push_front(q.back());
        q.pop_back();
      }
      cnt++;
    }

    q.pop_front();
  }

  cout << cnt;

  return 0;
}