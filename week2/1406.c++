#include <iostream>
#include <list>
using namespace std;

int main() {

  string s;
  list<char> l;
  int n, cursur = s.length() - 1;

  cin >> s >> n;

  l.push_back(0);
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
      if (x != l.begin())
        x = l.erase(--x);
    } else if (cmd == 'P') {
      char c;
      cin >> c;

      x = l.insert(x, c);
    }
  }

  for (list<char>::iterator i = l.begin(); i != l.end(); i++)
    cout << *i;

  return 0;
}