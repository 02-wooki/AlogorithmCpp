#include <iostream>
using namespace std;

void Nto1(int n) {
  if (n) {
    cout << n-- << '\n';
    Nto1(n);
  }
  return;
}

int sumN(int n) {
  if (n > 1)
    return sumN(n - 1) + n;
  else
    return 1;
}


int main() {

  Nto1(20);
  cout << '\n' << sumN(10) << '\n';

  return 0;
}