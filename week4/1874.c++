#include <iostream>
#include <stack>
using namespace std;

#define MAX 100001

int main() {

  string result = "";
  stack<int> s;
  int cur = 1;

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    while (cur <= x) {
        result.append ("+\n");
        s.push(cur++);
    }
    if (!s.empty() && s.top() == x) {
      result.append("-\n");
      s.pop();
    } else {
      cout << "NO";
      return 0;
    }
  }

  cout << result;

  return 0;
}