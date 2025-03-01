#include <iostream>
#include <string>
using namespace std;

long long fact(long long x) {
    if (x < 2)
        return x;
    return x * fact(x - 1);
}

int main() {
    int n, result = 0;
    cin >> n;

    string x = to_string(fact((long long) n));
    for (int i = x.length() - 1; i >= 0; --i) {
        if (x[i] != '0')
            break;
        result++;
    }

    cout << result;
}
