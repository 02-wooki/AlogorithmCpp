#include <iostream>
using namespace std;

int main() {
    int n, k, result = 0;
    cin >> n >> k;

    int coins[n];
    for (int i = 0; i < n; ++i)
        cin >> coins[i];

    for (int i = n - 1; i >= 0; --i) {
        result += k / coins[i];
        k = k % coins[i];
    }

    cout << result;
}
