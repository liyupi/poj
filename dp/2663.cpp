// https://blog.csdn.net/u013480600/article/details/19612171
#include <iostream>

using namespace std;

const int MAXN = 31;

int dp[MAXN];

int main() {
    int n;
    dp[0] = 1;
    while (scanf("%d", &n) && n != -1) {
        for (int i = 2; i <= n; ++i) {
            dp[i] = 3 * dp[i - 2];
            int tmp = i - 4;
            while (tmp >= 0) {
                dp[i] += dp[tmp] * 2;
                tmp -= 2;
            }
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}

