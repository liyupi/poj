// http://poj.org/problem?id=1017
#include <iostream>

using namespace std;


int a[7];
int bu3[2][4] = {{0, 27, 18, 9},
                 {0, 5,  3,  1}};

int main() {
    while (true) {
        bool flag = true;
        for (int i = 1; i <= 6; ++i) {
            scanf("%d", &a[i]);
            if (a[i]) {
                flag = false;
            }
        }
        if (flag) {
            break;
        }
        int sum = a[6] + a[5] + a[4] + (a[3] + 3) / 4;
        int left1 = 0;
        int left2 = 0;
        a[3] %= 4;
        left1 += a[5] * 11 + a[4] * 20 + bu3[0][a[3]];
        left2 += a[4] * 5 + bu3[1][a[3]];
        while (left2 < a[2]) {
            left2 += 9;
            left1 += 36;
            sum += 1;
        }
        left1 -= a[2] * 4;
        while (left1 < a[1]) {
            left1 += 36;
            sum += 1;
        }
        cout << sum << endl;
    }
    return 0;
}