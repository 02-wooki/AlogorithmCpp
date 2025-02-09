#include <iostream>
#include <stack>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  long long cnt = 0;
  stack<long long> s;

  while(n--) {
    long long height;
    cin >> height;

    while (!s.empty() && height >= s.top())
      s.pop();

    cnt += s.size();

    s.push(height);
  }

  cout << cnt << '\n';

  return 0;
}