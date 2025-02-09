#include <iostream>

#define MAX 246913

using namespace std;

int main() {

  bool sosu[MAX];
  for (int i = 0; i < 2; i++)
    sosu[i] = false;
  for (int i = 2; i < MAX; i++)
    sosu[i] = true;

  for (int i = 2; i * i < MAX; i++) {
    if (!sosu[i])
      continue;

    for (int j = i * i; j < MAX; j += i)
      sosu[j] = false;
  }

  int n;
  cin >> n;
  while(n != 0) {
    int cnt = 0;
    for (int i = n + 1; i <= n * 2; i++) {
      if (sosu[i])
        cnt++;
    }
    cout << cnt << '\n';
    cin >> n;
  }

  return 0;
}