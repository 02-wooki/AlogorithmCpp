#include <iostream>
using namespace std;

int main() {

  int n, k;
  cin >> n >> k;

  bool *deleted = (bool*)malloc(sizeof(bool) * (n + 1));
  for (int i = 0; i < n + 1; i++)
    deleted[i] = false;

  cout << '<';

  int cnt = 0, i = 0;
  while (cnt < n) {
    for (int j = 0; j < k; j++) {
      i = (i + 1) % n;
      if (deleted[i])
        j--;
    }

    deleted[i] = true;
    cout << (cnt != 0 ? ", " : "") << (i == 0 ? n : i);
    cnt++;
  }

  cout << ">";

  return 0;
}