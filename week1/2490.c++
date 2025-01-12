#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 3; i++) {
        int arr[4];
        cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];

        int cnt (0);
        for (int j = 0; j < 4; j++)
            if (arr[j] == 0)
                cnt++;

        switch (cnt) {
            case 0:
                cout << 'E';    break;
            case 1:
                cout << 'A';    break;
            case 2:
                cout << 'B';    break;
            case 3:
                cout << 'C';    break;
            case 4:
                cout << 'D';    break;
            default:    break;
        }
        cout << endl;
    }
    return 0;
}