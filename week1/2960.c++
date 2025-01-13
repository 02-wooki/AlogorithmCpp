#include <iostream>
using namespace std;

int main() {

  int n, k;
  cin >> n >> k;

  bool sosu[1001];
  for (int i = 0; i < 1001; i++)
    sosu[i] = true;
  
  int cnt = 0;
  for (int i = 2; i <= n; i++) {
    if (!sosu[i])
      continue;
    for (int j = i; j <= n; j += i) {
      if (sosu[j] && ++cnt >= k) {
        cout << j;
        return 0;
      }
      sosu[j] = false;
    }
  }

  return 0;
}