#include <iostream>
#include <vector>
using namespace std;

int main() {

  int n;
  cin >> n;

  vector<int> v(201);
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v[x + 100]++;
  }

  int target;
  cin >> target;
  cout << v[target + 100];

  return 0;
}