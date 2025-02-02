#include <iostream>
#include <deque>
using namespace std;

deque<int> dq;

int main() {

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    if (!s.compare("push_front") || !s.compare("push_back")) {
      int x;
      cin >> x;

      if (!s.compare("push_front"))
        dq.push_front(x);
      else
        dq.push_back(x);
    } else if (!s.compare("pop_front")) {
      if (dq.empty())
        cout << -1 << '\n';
      else {
        cout << dq.front() << '\n';
        dq.pop_front();
      }
    } else if (!s.compare("pop_back")) {
      if (dq.empty())
        cout << -1 << '\n';
      else {
        cout << dq.back() << '\n';
        dq.pop_back();
      }
    } else if (!s.compare("size")) {
      cout << dq.size() << '\n';
    } else if (!s.compare("empty")) {
      cout << (dq.empty() ? 1 : 0) << '\n';
    } else if (!s.compare("front")) {
      cout << (dq.empty() ? -1 : dq.front()) << '\n';
    } else if (!s.compare("back")) {
      cout << (dq.empty() ? -1 : dq.back()) << '\n';
    }
  }

  return 0;
}