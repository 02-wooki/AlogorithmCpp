#include <iostream>
using namespace std;

int main() {

  int sum = 0;
  int min = 100;
  int x;
  for (int i = 0; i < 7; i++) {
    cin >> x;

    // 홀수 판별
    if (x % 2 == 0) continue;

    sum += x;     // 합 구하기
    if (min > x)  // 최소값 찾기
      min = x;
  }

  if (sum == 0)
    cout << -1 << endl;
  else
    cout << sum << endl << min << endl;

  return 0;
}