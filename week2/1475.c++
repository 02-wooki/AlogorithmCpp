#include <iostream>
using namespace std;

int max(int *arr, int size) {
  int maxValue = -1;

  for (int i = 0; i < size; i++)
    if (maxValue < arr[i])
      maxValue = arr[i];

  return maxValue;
}

int main() {

  int num;
  cin >> num;

  int set[10] = { 0, };
  while (num > 0) {
    set[num % 10]++;
    num /= 10;
  }

  set[6] = (set[6] + set[9] + 1) / 2;
  cout << max(set, 9);

  return 0;
}