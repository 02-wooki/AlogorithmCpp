#include <iostream>
using namespace std;

int lcm(int x, int y) {
  if (y == 0)
    return x;
  return lcm(y, x % y);
}

int main() {

  int t;
  cin >> t;
  
  for (int i = 0; i < t; i++) {
    int m, n, x, y;
    int j = 1, k = 1;
    cin >> m >> n >> x >> y;

    int year, death = n * m / lcm(m, n);
    if (x < y) {
      y = y - x + 1;
      year = x;
      x = 1;
    } else {
      x = x - y + 1;
      year = y;
      y = 1;
    }

    while (j != x || k != y) {
      // cout << "<" << j << ":" << k << "> " << year << endl;
      if (year >= death)
        break;
      if (m - j < n - k) {
        k += m - j + 1;
        year += m - j + 1;
        j = 1;
      } else {
        j += n - k + 1;
        year += n - k + 1;
        k = 1;
      }
    }

    if (j != x || k != y)
      cout << -1 << endl;
    else
      cout << year << endl;
  }

  return 0;
}