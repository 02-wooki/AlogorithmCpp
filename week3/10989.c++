#include <iostream>
using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int arr[10001] = { 0, };
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int x;
    cin >> x;

    arr[x]++;
  }

  for (int i = 0; i < 10001; i++) {
    while (arr[i]-- > 0)
      cout << i << '\n';
  }

  return 0;
}