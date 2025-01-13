#include <iostream>
using namespace std;

int main() {
  int i = 1;
  while (true) {
    int l, p, v;
    cin >> l >> p >> v;

    if (l + p + v == 0) break;

    int day = (v / p) * l;
    int remain = (v % p < l) ? v % p : l;

    cout << "Case " << i++ << ": " << day + remain << endl;
  }

  return 0;
}