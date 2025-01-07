// 세수정렬

#include <iostream>
using namespace std;

void swap(int *x, int *y) {
    int cup = *x;
    *x = *y;
    *y = cup;
}

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    
    if (x > y)
        swap(&x, &y);
    if (x > z)
        swap(&x, &z);
    if (y > z)
        swap(&y, &z);

    cout << x << ' ' << y << ' ' << z << endl;
    return 0;
}