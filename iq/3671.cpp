// http://poj.org/problem?id=3671
#include <iostream>

using namespace std;

const int MAXN = 30001;

int D[MAXN];

int sum1[MAXN];
int sum2[MAXN];

int main() {
    int N;
    while (~scanf("%d", &N)) {
        for (int i = 0; i < N; ++i) {
            scanf("%d", &D[i]);
        }
        sum1[0] = 0;
        sum2[0] = 0;
        for (int i = 1; i <= N; ++i) {
            sum1[i] = sum1[i - 1] + (D[i - 1] == 1);
            sum2[i] = sum2[i - 1] + (D[i - 1] == 2);
        }
        int res = 0;
        // 以每个点为边界，如果其左边的1+右边的2最多，则需要修改的最少
        for (int i = 0; i < N; ++i) {
            res = max(res, sum1[i] + sum2[N] - sum2[i + 1]);
        }
        printf("%d\n", N - 1 - res);
    }
    return 0;
}