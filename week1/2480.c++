#include <iostream>
using namespace std;

int max(int *arr) {
    int maxValue(0);
    
    for (int i = 0; i < 3; i++) {
        if (arr[i] > maxValue)
            maxValue = arr[i];
    }

    return maxValue;
}

int main() {
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];

    if (arr[0] == arr[1] && arr[1] == arr[2])
        cout << arr[0] * 1000 + 10000;
    else if (arr[0] == arr[1] || arr[0] == arr[2])
        cout << arr[0] * 100 + 1000;
    else if (arr[1] == arr[2])
        cout << arr[1] * 100 + 1000;
    else
        cout << max(arr) * 100;

    return 0;
}