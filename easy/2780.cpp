// http://poj.org/problem?id=2780
#include <iostream>

using namespace std;

const int MAXN = 1001;

int x[MAXN], y[MAXN];

int main() {
    int n;
    while (~scanf("%d", &n)) {
        int res = 2;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &x[i], &y[i]);
        }
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                int sum = 2;
                int a = x[i] - x[j];
                int b = y[i] - y[j];
                for (int k = j + 1; k < n; ++k) {
                    if (a * (y[k] - y[j]) == (x[k] - x[j]) * b) {
                        sum++;
                    }
                }
                res = max(res, sum);
            }
        }
        printf("%d\n", res);
    }
    return 0;
}

