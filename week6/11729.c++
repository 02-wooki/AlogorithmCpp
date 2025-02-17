#include <iostream>
using namespace std;

void hanoi(int a, int b, int n) {
  
  if (n == 1) {
    cout << a << ' ' << b << '\n';
    return;
  }

  // n-1개 원판을 나머지 기둥으로 옮긴다
  if (n > 1)
    hanoi(a, 6 - a - b, n - 1);
  
  // n번 원판을 기둥 a에서 b로 옮긴다
  cout << a << ' ' << b << '\n';

  // n - 1개의 원판을 기둥 6 - a - b에서 기둥 b로 옮긴다
  hanoi(6 - a - b, b, n - 1);  

  return;
}


int main() {

  int n;
  cin >> n;

  cout << (1 << n) - 1 << '\n';
  hanoi(1, 3, n);

  return 0;
}