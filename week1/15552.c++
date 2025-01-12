#include <iostream>
using namespace std;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(NULL);

  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int x, y;
    cin >> x >> y;
    cout << x + y << '\n';
  }

  return 0;
}