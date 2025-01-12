#include <iostream>
using namespace std;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  long long s, e;
  cin >> s >> e;

  if (e == s)
    cout << 0;
  else if (s < e) {
    cout << e - s - 1 << endl;
    for (long long i = s + 1; i < e; i++)
      cout << i << ' ';
  }
  else {
    cout << s - e - 1 << endl;
    for (long long i = e + 1; i < s; i++)
      cout << i << ' ';
  }

  return 0;
}