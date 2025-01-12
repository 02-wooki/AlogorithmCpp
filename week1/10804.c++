#include <iostream>
using namespace std;

int main() {

  int arr[21];
  for (int i = 0; i < 21; i++)
    arr[i] = i;

  for (int t = 0; t < 10; t++) {
    int s, e;
    cin >> s >> e;

    int i = s;
    int j = e;

    while (i < j) {
      int tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;

      i++; j--;
    }
  }

  for (int i = 1; i < 21; i++)
    cout << arr[i] << ' ';

  return 0;
}