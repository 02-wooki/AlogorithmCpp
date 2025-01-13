#include <iostream>
using namespace std;

int main() {

  int x;
  cin >> x;

  if (x < 60)
    cout << 'F';
  else if (x < 70)
    cout << 'D';
  else if (x < 80)
    cout << 'C';
  else if (x < 90)
    cout << 'B';
  else
    cout << 'A';

  return 0;
}