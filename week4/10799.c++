#include <iostream>
#include <stack>
using namespace std;

int main() {

  int pieces = 0;
  stack<int> s;
  string str;
  cin >> str;

  for(int i; i < str.length(); i++) {
    if (str[i] == '(') {
      s.push(i);
    } else {
      if (s.top() == i - 1) {
        s.pop();
        pieces += s.size();
      } else  {
        pieces++;
        s.pop();
      }
    }
  }

  cout << pieces;

  return 0;
}