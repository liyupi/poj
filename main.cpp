// https://blog.csdn.net/lyy289065406/article/details/6642603
// 条件：连续5个月的总额必亏损
// ssddd ssddd ss
#include <iostream>

using namespace std;

int main() {
    int s, d;
    while (cin >> s >> d) {
        int sum = 0;
        if (4 * s < d) {
            sum = 10 * s - 2 * d;
        } else if (3 * s < 2 * d) {
            sum = 8 * s - 4 * d;
        } else if (2 * s < 3 * d) {
            sum = 6 * s - 6 * d;
        } else if (s < 4 * d) {
            sum = 3 * s - 9 * d;
        } else {
            sum = -1;
        }
        if (sum < 0) {
            cout << "Deficit" << endl;
        } else {
            cout << sum << endl;
        }

    }
    return 0;
}