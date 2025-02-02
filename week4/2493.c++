#include <iostream>
#include <stack>
using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  stack<int> s;
  int height[n];

  for (int i = 0; i < n; i++) {
    cin >> height[i];

    // i번째 탑보다 작으면 어짜피 다음 탑의 신호도 못받음
    while (!s.empty() && height[s.top()] <= height[i]) {
      s.pop();
    }

    // i번째 탑의 신호를 받은 탑 기록
    if (s.empty())
      cout << "0 ";
    else
      cout << s.top() + 1 << ' ';

    s.push(i);
  }

  return 0;
}