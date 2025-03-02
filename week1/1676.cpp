#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, result = 0;
    cin >> n;

    while (n) {
        result += n / 5;
        n /= 5;
    }

    cout << result;
}
