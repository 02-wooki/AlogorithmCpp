#include <iostream>
using namespace std;

int main() {

  int max = 0;
  int maxIdx = 0;
  for (int i = 1; i < 10; i++) {
    int x;
    cin >> x;

    if (x > max) {
      max = x;
      maxIdx = i;
    }
  }

  cout << max << endl << maxIdx;

  return 0;
}