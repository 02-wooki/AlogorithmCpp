#include <iostream>
using namespace std;

int main() {

  int t;
  cin >> t;

  int q[t];
  int head = 0;
  int tail = 0;
  for (int i = 0; i < t; i++) {
    string cmd;
    cin >> cmd;

    if (cmd == "push") {
      int x;
      cin >> x;

      q[head++] = x;
    }

    else if (cmd == "pop") {
      if (head == tail)
        cout << -1 << '\n';
      else
        cout << q[tail++] << '\n';
    }

    else if (cmd == "size") {
      cout << head - tail << '\n';
    }

    else if (cmd == "empty") {
      cout << (head == tail ? 1 : 0) << '\n';
    }

    else if (cmd == "front") {
      if (head == tail)
        cout << -1 << '\n';
      else
        cout << q[tail] << '\n';
    }

    else if (cmd == "back") {
      if (head == tail)
        cout << -1 << '\n';
      else
        cout << q[head - 1] << '\n';
    }
  }

  return 0;
}