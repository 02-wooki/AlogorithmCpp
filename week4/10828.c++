#include <iostream>
using namespace std;

int main() {

  int t;
  cin >> t;

  int s[t];
  int pos = 0;

  for (int i = 0; i < t; i++) {
    string cmd;
    cin >> cmd;

    if (cmd == "push") {
        int x;
        cin >> x;
        s[pos++] = x;
    } else if (cmd == "pop") {
        if (pos == 0)
          cout << -1 << '\n';
        else
          cout << s[--pos] << '\n';
    } else if (cmd == "size") {
        cout << pos << '\n';
    } else if (cmd == "empty") {
        cout << (pos == 0 ? 1 : 0) << '\n';
    } else if (cmd == "top") {
        if (pos == 0)
          cout << -1 << '\n';
        else
          cout << s[pos - 1] << '\n';
    }
  }

  return 0;
}