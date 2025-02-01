#include <iostream>
#include <stack>
using namespace std;

int main() {

  int n;
  cin >> n;
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    stack<char> s;
    string str;
    cin >> str;

    for (char c: str) {
      if (!s.empty() && s.top() == c)
          s.pop();
      else
        s.push(c);
    }
    
    cnt += s.empty() ? 1 : 0;
  }
  cout << cnt;

  return 0;
}