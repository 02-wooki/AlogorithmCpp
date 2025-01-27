#include <iostream>
using namespace std;

int main() {

  int t;
  cin >> t;

  int s[t];
  int pos = 0;

  for (int i = 0; i < t; i++) {
    int x;
    cin >> x;

    if (x == 0)
      pos--;
    else
      s[pos++] = x;
  }

  int sum = 0;
  for (int i = 0; i < pos; i++)
    sum += s[i];
  
  cout << sum;

  return 0;
}