// http://poj.org/problem?id=2262
#include <iostream>

using namespace std;

const int MAXN = 1000001;

int notPrime[MAXN] = {0};

void init() {
    for (int i = 2; i < MAXN; ++i) {
        if (!notPrime[i]) {
            int j = 2;
            int num = i * j;
            while (num < MAXN) {
                notPrime[num] = 1;
                j++;
                num = i * j;
            }
        }
    }
}

int main() {
    init();
    int n;
    while (cin >> n) {
        if (!n) {
            break;
        }
        int maxNum = n / 2;
        for (int i = 2; i <= maxNum; ++i) {
            if (!notPrime[i] && !notPrime[n - i]) {
                printf("%d = %d + %d\n", n, i, n - i);
                break;
            }
        }
    }
    return 0;
}
