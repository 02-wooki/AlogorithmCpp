#include <iostream>
using namespace std;

bool visited[9];
int size;

void sequence(int n, int m, int* arr) {
  // base condition
  if (m == 0) {
    for (int i = 0; i < size; i++) {
      cout << arr[i] << ' ';
    }
    cout << '\n';
    return;
  }

  
  for (int i = 1; i <= n; i++) {
    if (visited[i])
      continue;
    
    visited[i] = true;
    arr[size - m] = i;
    sequence(n, m - 1, arr);
    visited[i] = false;
  }
}

int main() {

  int n, m;
  cin >> n >> m;

  int arr[m];
  size = m;

  for (int i = 0; i < 9; i++) {
    visited[i] = false;
  }

  sequence(n, m, arr);

  return 0;
}