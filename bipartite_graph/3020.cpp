// http://poj.org/problem?id=3020
// 最大独立点集 = 总顶点数 - 最大匹配数
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 450;

int map[41][11];
bool used[MAXN];
int girls[MAXN];
int graph[MAXN][MAXN];

int num;

int h, w;

bool find(int m) {
    for (int i = 1; i <= num; ++i) {
        if (graph[m][i] && !used[i]) {
            used[i] = 1;
            if (!girls[i] || find(girls[i])) {
                girls[i] = m;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> h >> w;
        num = 0;
        memset(girls, 0, sizeof(girls));
        memset(graph, 0, sizeof(graph));
        // 抽象坐标为点
        for (int i = 0; i < h; ++i) {
            getchar();
            for (int j = 0; j < w; ++j) {
                char c;
                scanf("%c", &c);
                if (c == '*') {
                    map[i][j] = ++num;
                } else {
                    map[i][j] = 0;
                }
            }
        }
        // 建立无向图
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (map[i][j] > 0) {
                    if (i != h - 1 && map[i + 1][j] > 0) {
                        graph[map[i][j]][map[i + 1][j]] = 1;
                        graph[map[i + 1][j]][map[i][j]] = 1;

                    }
                    if (j != w - 1 && map[i][j + 1] > 0) {
                        graph[map[i][j]][map[i][j + 1]] = 1;
                        graph[map[i][j + 1]][map[i][j]] = 1;
                    }
                }
            }
        }
        // 求最大匹配数
        int res = 0;
        for (int i = 1; i <= num; ++i) {
            memset(used, 0, sizeof(used));
            if (find(i)) {
                res++;
            }
        }
        // 无向图的最大匹配数为结果数 / 2
        printf("%d\n", num - res / 2);
    }
}
