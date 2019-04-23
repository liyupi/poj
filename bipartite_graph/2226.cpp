// https://www.cnblogs.com/zhanzhao/p/3920295.html
// 最小顶点覆盖（用最少的顶点覆盖所有的边）= 最大匹配数
// 本题中每个交点（*）看作一条图中的边，题意要求覆盖所有交点，即覆盖所有的边（最小顶点覆盖）
#include <iostream>
#include <cstring>

using namespace std;

const int MAXR = 51;
const int MAXC = 51;

// 输入
char map[MAXR][MAXC];
bool used[MAXC * MAXR];
int girls[MAXC * MAXR];
int graph[MAXC * MAXR][MAXC * MAXR];
// 列联通块
int col[MAXR][MAXC];
// 行联通块
int row[MAXR][MAXC];

int R, C;
int rowNum, colNum, num;

bool find(int man) {
    for (int i = 1; i <= num; ++i) {
        if (graph[man][i] && !used[i]) {
            used[i] = true;
            if (!girls[i] || find(girls[i])) {
                girls[i] = man;
                return true;
            }
        }
    }
    return false;
}

int main() {
    while (~scanf("%d%d", &R, &C)) {
        memset(girls, 0, sizeof(girls));
        memset(graph, 0, sizeof(graph));
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        rowNum = colNum = 0;
        char c;
        getchar();
        // 输入
        for (int i = 1; i <= R; ++i) {
            for (int j = 1; j <= C; ++j) {
                scanf("%c", &map[i][j]);
            }
            getchar();
        }
        // 构造联通块（联通的块具有相同编号即可）
        for (int i = 1; i <= R; ++i) {
            for (int j = 1; j <= C; ++j) {
                if (map[i][j] == '*') {
                    if (row[i - 1][j]) {
                        row[i][j] = row[i - 1][j];
                    } else {
                        row[i][j] = ++rowNum;
                    }
                    if (col[i][j - 1]) {
                        col[i][j] = col[i][j - 1];
                    } else {
                        col[i][j] = ++colNum;
                    }
                }
            }
        }
        // 利用交点建图
        for (int i = 1; i <= R; ++i) {
            for (int j = 1; j <= C; ++j) {
                if (map[i][j] == '*') {
                    graph[row[i][j]][col[i][j]] = 1;
                }
            }
        }
        int res = 0;
        num = max(rowNum, colNum);
        // 二分图匹配
        for (int i = 1; i <= num; ++i) {
            memset(used, 0, sizeof(used));
            if (find(i)) {
                res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}