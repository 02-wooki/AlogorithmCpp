#include <iostream>
using namespace std;

int main() {

  int x;
  cin >> x;

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < x - i - 1; j++)
      cout << ' ';
    for (int j = 0; j < i * 2 + 1; j++)
      cout << '*';
    cout << '\n';
  }

  return 0;
}