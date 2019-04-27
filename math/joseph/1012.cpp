// https://blog.csdn.net/Jaster_wisdom/article/details/51496525
#include <iostream>

using namespace std;

int res[15] = {0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881, 13482720};

int main() {
    int k;
    while (cin >> k && k) {
        int next = 0;
        int n = 2 * k;
        int m = k + 1;
        while (true) {
            for (int i = 1; i <= k; ++i) {
                next = (next + m - 1) % (n - i + 1);
                if (next < k) {
                    next = 0;
                    m++;
                    break;
                }
            }
            if (next) {
                break;
            }
        }
        printf("%d\n", res[k]);
    }
}