#include <iostream>
using namespace std;

int main() {

  int num[3];
  cin >> num[0] >> num[1] >> num[2];

  int cnt[10] = { 0, };
  int mul = num[0] * num[1] * num[2];

  while (mul > 0) {
    cnt[mul % 10]++;
    mul /= 10;
  }

  for (int i: cnt)
    cout << i << '\n';

  return 0;
}