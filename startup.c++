#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    float n;
    cin >> n;

    if (sqrt(n) == int(sqrt(n)))
        cout << 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}