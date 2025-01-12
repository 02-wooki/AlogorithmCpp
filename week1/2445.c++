#include <iostream>
using namespace std;

int main() {

  int x;
  cin >> x;

  for (int i = 0; i < x; i++) {
    for (int j = 0; j <= i; j++)
      cout << '*';
    for (int j = 0; j < (x - i - 1) * 2; j++)
      cout << ' ';
    for (int j = 0; j <= i; j++)
      cout << '*';
    cout << endl;
  }
  for (int i = 0; i < x - 1; i++) {
    for (int j = 0; j < x - i - 1; j++)
      cout << '*';
    for (int j = 0; j < (i + 1) * 2; j++)
      cout << ' ';
    for (int j = 0; j < x - i - 1; j++)
      cout << '*';
    cout << endl;
  }

  return 0;
}