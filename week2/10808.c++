#include <iostream>
using namespace std;

int main() {

  int alpha[26];
  for (int i = 0; i < 26; i++)
    alpha[i] = 0;

  string s;
  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    char x = s[i];
    alpha[x - 'a']++;
  }

  for (int i = 0; i < 26; i++)
    cout << alpha[i] << ' ';

  return 0;
}