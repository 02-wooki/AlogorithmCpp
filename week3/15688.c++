#include <iostream>
using namespace std;

#define SIZE 2000001
#define OFFSET 1000000

int main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  int *arr = (int *)malloc(sizeof(int) * SIZE);

  for (int i = 0; i < SIZE; i++)
    arr[i] = 0;

  cin >> t;
  for (int i = 0; i < t; i++) {
    int x;
    cin >> x;

    arr[x + OFFSET]++;
  }
  for (int i = 0; i < SIZE; i++) {
    while (arr[i]-- > 0)
      cout << i - OFFSET << '\n';
  }

  return 0;
}