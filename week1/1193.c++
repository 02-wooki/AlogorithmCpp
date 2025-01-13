#include <iostream>
using namespace std;

int main() {

  int x;
  cin >> x;

  int hap = 2;
  bool isReversed = true;
  while (x > hap - 1) {
    x -= hap++ - 1;
    isReversed = !isReversed;
  }

  if (!isReversed)
    cout << x << '/' << hap - x;
  else
    cout << hap - x << '/' << x;

  return 0;
}