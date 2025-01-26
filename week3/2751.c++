#include <iostream>
using namespace std;
#define SIZE 2000001
#define HALF 1000000

int main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int *arr = (int*)malloc(sizeof(int) * SIZE);
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int x;
    cin >> x;

    arr[x + HALF]++;
  }

  for (int i = 0; i < SIZE; i++) {
    while (arr[i]-- > 0)
      cout << i - HALF << '\n';
  }

  return 0;
}