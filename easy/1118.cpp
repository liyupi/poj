// http://poj.org/problem?id=1118
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 711;

int x[MAXN], y[MAXN];

int main() {
    int N;
    while (~scanf("%d", &N) && N) {
        for (int i = 0; i < N; ++i) {
            scanf("%d%d", &x[i], &y[i]);
        }
        if (N < 3) {
            printf("%d\n", N);
            continue;
        }
        int res = 2;
        for (int i = 0; i < N - 2; ++i) {
            for (int j = i + 1; j < N - 1; ++j) {
                int tmpx = x[j] - x[i];
                int tmpy = y[j] - y[i];
                int num = 2;
                for (int k = j + 1; k < N; ++k) {
                    if ((x[k] - x[i]) * tmpy == (y[k] - y[i]) * tmpx) {
                        num++;
                    }
                }
                res = max(res, num);
            }
        }
        printf("%d\n", res);
    }
}

