#include <iostream>
using namespace std;

void sort(int *arr) {
  // 버블 정렬
  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 5; j++) {
      if (arr[i] > arr[j]) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
      }
    }
  }
}

int sum(int *arr) {
  int sum = 0;
  for (int i = 0; i < 5; i++)
    sum += arr[i];
  return sum;
}

int main() {

  int arr[5];
  cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];

  sort(arr);
  
  cout << int(sum(arr) / 5) << endl << arr[2] << endl;

  return 0;
}