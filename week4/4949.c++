#include <iostream>
#include <stack>
using namespace std;

int main() {

  string str;
  getline(cin, str);
  while(str.length() != 1) {
    stack<char> brace;
    string possible = "yes";

    for (char c: str) {
      if (c == '(')
        brace.push(')');
      else if (c == '[')
        brace.push(']');
      else if (c == ')' || c == ']') {
        if (!brace.empty()) {
          if (brace.top() != c) {
            possible = "no";
            break;
          }
          brace.pop();
        } else {
          possible = "no";
          break;
        }
      }
    }
    if (!brace.empty())
      possible = "no";
    
    cout << possible << '\n';
    getline(cin, str);
  }

  return 0;
}