#include <iostream>
using namespace std;

#define SIZE 2000001
#define OFFSET 1000000

int main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  bool *arr = (bool*)malloc(sizeof(bool) * SIZE);
  for (int i = 0; i < SIZE; i++)
    arr[i] = false;

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int x;
    cin >> x;

    arr[x + OFFSET] = true;
  }

  for (int i = SIZE - 1; i >= 0; i--) {
    if (arr[i])
      cout << i - OFFSET << '\n';
  }

  return 0;
}