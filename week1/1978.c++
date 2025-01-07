 // 소수 찾기

#include <iostream>
using namespace std;

// 에라토스테네스의 체를 사용하지 않고 반복으로 구하는 방법
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

// 에라토스테네스의 체
int eratos(int n) {

    // 소수 상태 배열 선언과 초기화
    int cnt = 0;
    bool state[1001];

    for (int i = 0; i <= 1000; i++)
        state[i] = true;

    // 1부터 1000까지 소수 판별
    state[1] = false;
    for (int i = 2; i * i <= 1000; i++) {
        if (!state[i])
            continue;
        for (int j = i; j * i <= 1000; j++)
            state[i * j] = false;
    }

    // 입력받고 입력값 소수인지 판별
    for (int i = 0; i < n; i++) {
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

    cout << eratos(n) << endl;
    
    return 0;
}