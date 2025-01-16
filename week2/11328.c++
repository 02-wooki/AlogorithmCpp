#include <iostream>
using namespace std;

int main() {

  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    string origin, strfried;
    cin >> origin >> strfried;

    int cntOrigin[26] = { 0, }, cntStrfried[26] = { 0, };
    
    // 예외처리
    if (origin.length() != strfried.length()) {
      cout << "Impossible" << '\n';
      continue;
    }
    // 알파벳 개수 세기
    for (int i = 0; i < origin.length(); i++) {
      cntOrigin[origin.at(i) - 'a']++;
      cntStrfried[strfried.at(i) - 'a']++;
    }
    // 결과 판단
    bool possible = true;
    for (int i = 0; i < 26; i++) {
      if (cntOrigin[i] != cntStrfried[i]) {
        possible = false;
        break;
      }
    }

    cout << (possible == true ? "Possible" : "Impossible") << '\n';
  }
  return 0;
}