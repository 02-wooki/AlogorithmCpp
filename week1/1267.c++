#include <iostream>
using namespace std;

int main() {

  int n;
  cin >> n;

  int y = 0;
  int m = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    y += int((x + 1) / 30 + 1) * 10;
    m += int((x + 1) / 60 + 1) * 15;
  }

  if (y == m)
    cout << "Y M " << y;
  else if (y < m)
    cout << "Y " << y;
  else
    cout << "M " << m;

  return 0;
}