#include <iostream>
using namespace std;

int main() {

  int t;
  cin >> t;

  const int size = t * 2;
  int dq[size];
  int head = t;
  int tail = t;

  for (int i = 0; i < t; i++) {
    string cmd;
    cin >> cmd;

    if (cmd == "push_front") {
      int x;
      cin >> x;

      dq[--head] = x;
    }

    else if (cmd == "push_back") {
      int x;
      cin >> x;

      dq[tail++] = x;
    }

    else if (cmd == "pop_front") {
      if (tail == head)
        cout << -1 << '\n';
      else
        cout << dq[head++] << '\n';
    }

    else if (cmd == "pop_back") {
      if (tail == head)
        cout << -1 << '\n';
      else
        cout << dq[--tail] << '\n';
    }

    else if (cmd == "size") {
      cout << head - tail << '\n';
    }

    else if (cmd == "empty") {
      cout << (head == tail ? 1 : 0) << '\n';
    }

    else if (cmd == "front") {
      cout << dq[head] << '\n';
    }

    else if (cmd == "back") {
      cout << dq[tail - 1] << '\n'; 
    }
  }

  return 0;
}