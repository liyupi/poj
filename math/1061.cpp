// https://blog.csdn.net/destiny1507/article/details/81750874
// todo 扩展欧几里得求出通解后，要求出最小解，不太懂
#include <iostream>

using namespace std;

// 求最大公约数的同时更新x、y
long long extGcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        long long r = extGcd(b, a % b, y, x);
        y -= x * (a / b);
        return r;
    }
}

int main() {
    long long x, y, m, n, L;
    long long a, b, c, gcd;
    while (~scanf("%lld %lld %lld %lld %lld", &x, &y, &m, &n, &L)) {
        a = m - n;
        b = L;
        c = y - x;
        if (a < 0) {
            c = -c;
            a = -a;
        }
        gcd = extGcd(a, b, x, y);
        if (c % gcd) {
            printf("Impossible\n");
        } else {
            long long r = L / gcd;
            printf("%d\n", (x * c / gcd % r + r) % r);
        }
    }
}

