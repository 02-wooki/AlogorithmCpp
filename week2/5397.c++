#include <iostream>
#include <vector>
using namespace std;

int main() {

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    vector<char> v;
    int curs = 1;
    string cmd;

    cin >> cmd;
    v.push_back(NULL);

    for (int j = 0; j < cmd.length(); j++) {
      if (cmd.at(j) == '<')
        curs -= curs > 0 ? 1 : 0;
      else if (cmd.at.(j) == '>')
        curs += curs < v.size()
    }
  }

  return 0;
}