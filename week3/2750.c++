#include <iostream>
using namespace std;


int main() {

    bool arr[2001] = { false, };

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[x + 1000] = true;
    }

    for (int i = 0; i < 2001; i++) {
        if (arr[i])
            cout << i - 1000 << '\n';
    }

    return 0;
}