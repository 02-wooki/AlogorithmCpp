#include <iostream>
using namespace std;

int sumarr(int *arr) {
  int sum = 0;
  for (int i = 0; i < 9; i++)
      sum += arr[i];
  return sum;
}

void sort(int *arr) {
  for (int i = 0; i < 8; i++) {
    for (int j = i + 1; j < 9; j++) {
      if (arr[i] > arr[j]) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
      }
    }
  }
}

int main() {

  int arr[9];
  for (int i = 0; i < 9; i++)
    cin >> arr[i];

  sort(arr);
  int sum = sumarr(arr);

  // 9개 중 7개를 남겨야 하므로 두개씩 빼본다
  int i = 0;
  int j = 8;
  while (sum - arr[i] - arr[j] != 100) {
    // arr[i], arr[j]를 뺀 합이 100 초과인 경우:
    // arr[i] + arr[j]가 빼야 할 목표보다 작은 것 -> i를 더 큰 값 쪽으로 옮긴다
    if (sum - arr[i] - arr[j] > 100)
      i++;
    // arr[i], arr[j]를 뺀 값이 100 미만인 경우: 
    // arr[i] + arr[j]가 빼야 할 목표보다 큰 것 -> j를 더 작은 값 쪽으로 옮긴다.
    else
      j--;
  }

  for (int k = 0; k < 9; k++)
    if (k != i && k != j)
      cout << arr[k] << endl;

  return 0;
}