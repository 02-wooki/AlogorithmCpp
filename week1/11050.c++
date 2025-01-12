#include <iostream>
using namespace std;

int fact(int n) {
  if (n < 2)
    return 1;
  return n * fact(n - 1);
}

int main() {

  int n, k, c = 1;
  cin >> n >> k;

  if (k > n / 2)
    k = n - k;

  for (int i = n; i > n - k; i--)
    c *= i;

  cout << c / fact(k);

  return 0;
}