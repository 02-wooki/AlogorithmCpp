#include <iostream>
using namespace std;

int main() {

  int n, k;
  int cnt = 0;
  int room[2][7] = {{ 0, }, };

  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    int s, y;
    cin >> s >> y;
    room[s][y]++;
  }

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 7; j++)
      cnt += room[i][j] % k == 0 ? room[i][j] / k : room[i][j] / k + 1;

  cout << cnt;

  return 0;
}