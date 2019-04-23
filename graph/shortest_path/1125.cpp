// https://www.cnblogs.com/GumpYan/p/5540549.html
// https://blog.csdn.net/y990041769/article/details/37955253
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 105;
const int INF = 1000000;

int edge[MAXN][MAXN];
int N;

int main() {
    while (cin >> N && N) {
        int m, a, b;
        // 初始化
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                edge[i][j] = INF;
                if (i == j) {
                    edge[i][j] = 0;
                }
            }
        }
        for (int i = 1; i <= N; ++i) {
            scanf("%d", &m);
            for (int j = 1; j <= m; ++j) {
                scanf("%d%d", &a, &b);
                edge[i][a] = b;
            }
        }
        // Floyd
        int minNum = INF;
        int minPos = 0;
        // 假设最初只有1个点可中转，求任两点之间最短路，再依次增加中转点
        for (int k = 1; k <= N; ++k) {
            for (int i = 1; i <= N; ++i) {
                int maxNum = -1;
                for (int j = 1; j <= N; ++j) {
                    edge[i][j] = min(edge[i][k] + edge[k][j], edge[i][j]);
                    maxNum = max(maxNum, edge[i][j]);
                }
                if (maxNum < minNum) {
                    minPos = i;
                    minNum = maxNum;
                }
            }
        }
        cout << minPos << " " << minNum << endl;
    }
    return 0;
}