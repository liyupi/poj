// https://blog.csdn.net/kid_u_forfun/article/details/8214117
// 二次函数最小值
#include <iostream>
#include <cmath>

using namespace std;

long long a;

int main() {
    while (cin >> a) {
        long long tmp = a * a + 1;
        for (int i = a; i > 0; i--) {
            // b + c是整数，由于函数单调递减，第一个找到的一定是最小值
            if (tmp % i == 0) {
                printf("%lld\n", i + 2 * a + tmp / i);
                break;
            }
        }
    }
}

