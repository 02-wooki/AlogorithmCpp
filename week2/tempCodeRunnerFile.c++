#include <iostream>
#include <list>
using namespace std;

int main() {

  string s;
  list<char> l;
  int n, cursur = s.length() - 1;

  cin >> s >> n;

  for (int i = 0; i < s.length(); i++)
    l.push_back(s.at(i));

  list<char>::iterator x = l.end();

  for (int i = 0; i < n; i++) {
    char cmd;
    cin >> cmd;

    if (cmd == 'L') {
      if (x != l.begin()) x--;
    } else if (cmd == 'D') {
      if (x != l.end()) x++;
    } else if (cmd == 'B') {
      x = l.erase(x);
      if (x != l.begin()) x--;
    } else if (cmd == 'P') {
      char c;
      cin >> c;

      x = l.insert(x, c);
    }
  }
  

  return 0;
}