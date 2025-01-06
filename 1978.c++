 // 소수 찾기

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int cnt = 0;
    for (int k = 0; k < n; k++) {
        int x;
        bool isSosu = true;

        cin >> x;
        if (x == 1)
            continue;
        
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                isSosu = false;
                break;
            }
        }
        if (isSosu)
            cnt++;
    }

    cout << cnt << endl;
    return 0;
}