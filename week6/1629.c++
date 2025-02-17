#include <iostream>
using namespace std;

long long POW(long long a, long long b, long long m) {
  // base condition
  if (b == 1)
    return a % m;

  long long val = POW(a, b / 2, m);
  val = val * val % m;

  if (b % 2 == 0)
    return val;
  return val * a % m;
}

int main() {
  long long a, b, c;
  cin >> a >> b >> c;

  cout << POW(a, b, c);

  return 0;
}