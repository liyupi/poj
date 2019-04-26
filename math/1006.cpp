// https://blog.csdn.net/d_x_d/article/details/48467255
// 中国剩余定理
#include <iostream>
#include <cmath>

using namespace std;

int r1, r2, r3, r;

void solve() {
    int i;
    int tmp;
    for (i = 1, r1 = 28 * 33 ; ;++i) {
        tmp = r1 * i;
        if (tmp % 23 == 1) {
            r1 = tmp;
            break;
        }
    }
    for (i = 1, r2 = 23 * 33 ; ;++i) {
        tmp = r2 * i;
        if (tmp % 28 == 1) {
            r2 = tmp;
            break;
        }
    }
    for (i = 1, r3 = 23 * 28 ; ;++i) {
        tmp = r3 * i;
        if (tmp % 33 == 1) {
            r3 = tmp;
            break;
        }
    }
    r = 23 * 28 * 33;
}

int main() {
    int p, e, i, d;
    int count = 0;
    while (~scanf("%d%d%d%d", &p, &e, &i, &d) && (p != -1 || e != -1 || i != -1 || d != -1)) {
/*        int final = d + 21252;
        int res = 21252;
        p %= 23;
        e %= 28;
        i %= 33;
        for (int j = d + 1; j <= final; ++j) {
            if (j % 23 == p && j % 28 == e && j % 33 == i) {
                res = j - d;
                break;
            }
        }*/
        solve();
        // 第一次三个同时巅峰
        int res = (r1 * p + r2 * e + r3 * i) % r;
        if (res <= d) {
            // 再加一轮周期
            res += r;
        }
        printf("Case %d: the next triple peak occurs in %d days.\n", ++count, min(res - d, r));
    }
}