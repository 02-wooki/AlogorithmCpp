#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

  int n;
  cin >> n;
  
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  int goal;
  cin >> goal;

  sort(v.begin(), v.end());
  
  int cnt = 0;
  int i = 0, j = n - 1;
  while (i < j) {
    if (v[i] + v[j] < goal)
      i++;
    else if (v[i] + v[j] > goal)
      j--;
    else {
      i++;
      j--;
      cnt++;
    }
  }

  cout << cnt;
  return 0;
}