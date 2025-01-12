#include <iostream>
#include <vector>
using namespace std;

int main() {

  int m, n;
  cin >> m >> n;

  bool* sosu = new bool[n + 1];

  for (int i = 0; i < n + 1; i++)
    sosu[i] = true;

  sosu[1] = false;
  for (int i = 2; i * i < n + 1; i++) {
    if (!sosu[i])
      continue;
    for (int j = i * i; j < n + 1; j += i) {
      sosu[j] = false;
    }
  }

  for (int i = m; i < n + 1; i++) {
    if (sosu[i])
      cout << i << endl;
  }

  delete[] sosu;
  return 0;
}