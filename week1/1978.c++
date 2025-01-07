 // 소수 찾기

#include <iostream>
using namespace std;

int depricated(int n) {
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
    return cnt;
}

int eratos(int n) {
    int cnt = 0;
    bool *state = new bool[1001];
    
    for (int i = 0; i <= 1000; i++)
        state[i] = true;

    state[1] = false;
    for (int i = 2; i <= 100; i++) {
        if (!state[i])
            continue;
        
        for (int j = i; j * i <= 1000; j++)
            state[i * j] = false;
    }

    for (int i = 0; i <= n; i++) {
        int x;
        cin >> x;

        if (state[x])
            cnt++;
    }
    
    return cnt;
}

int main() {
    int n;
    cin >> n;

    cout << eratos(n);
    
    return 0;
}