#include <iostream>
#include <stack>
using namespace std;

int main() {

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    stack<char> s;
    bool yes = true;
    string str;
    cin >> str;

    for (char c: str) {
      if (c == '(')
        s.push('(');
      else {
        if (s.empty()) {
          yes = false;
          break;
        } else
          s.pop();
      }
    }

    if (!s.empty())
      yes = false;
    
    cout << (yes ? "YES" : "NO") << '\n';
  }

  return 0;
}