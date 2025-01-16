#include <iostream>
using namespace std;

int main() {

  string str[2];
  int cnt[2][26] = {{ 0, }, };

  cin >> str[0] >> str[1];

  for (int i = 0; i < str[0].length(); i++)
    cnt[0][str[0].at(i) - 'a']++;
  for (int i = 0; i < str[1].length(); i++)
    cnt[1][str[1].at(i) - 'a']++;

  int result = 0;
  for (int i = 0; i < 26; i++) {
    if (cnt[0][i] != cnt[1][i]) {
      int diff = cnt[0][i] - cnt[1][i];
      result += diff * (diff < 0 ? -1 : 1);
    }
  }

  cout << result;
  return 0;
}