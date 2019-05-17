// https://blog.csdn.net/libin56842/article/details/21116143
#include <iostream>
#include <cstring>

using namespace std;

const int MAXC = 20;
const int MAXG = 20;
const int MAXB = 15000;

int C, G;

int hooks[MAXC];
int weight[MAXG + 1];
// 挂i个钩子时达到j平衡度的方法总数
int dp[MAXG + 1][MAXB + 1];

int main() {
    while (~scanf("%d%d", &C, &G)) {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < C; ++i) {
            scanf("%d", &hooks[i]);
        }
        for (int i = 1; i <= G; ++i) {
            scanf("%d", &weight[i]);
        }
        dp[0][7500] = 1;
        for (int i = 1; i <= G; ++i) {
            for (int j = 0; j <= MAXB; ++j) {
                if (dp[i - 1][j]) {
                    for (int k = 0; k < C; ++k) {
                        dp[i][j + weight[i] * hooks[k]] += dp[i - 1][j];
                    }
                }
            }
        }
        printf("%d\n", dp[G][7500]);
    }
    return 0;
}