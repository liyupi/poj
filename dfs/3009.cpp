// http://poj.org/problem?id=3009
// 注意step的数量超过10就可以结束了
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 21;
const int MAX_TIME = 11;
const int dirs[][2] = {{1,  0},
                       {-1, 0},
                       {0,  1},
                       {0,  -1}};
int m, n;
int map[MAXN][MAXN];

int res;

void dfs(int x, int y, int step) {
    if (step > 10) {
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int nx = x;
        int ny = y;
        bool first = true;
        while (true) {
            nx += dirs[i][0];
            ny += dirs[i][1];
            if (nx >= 0 && nx <= m - 1 && ny >= 0 && ny <= n - 1) {
                if (map[nx][ny] == 1) {
                    if (first) {
                        break;
                    }
                    map[nx][ny] = 0;
                    dfs(nx - dirs[i][0], ny - dirs[i][1], step + 1);
                    map[nx][ny] = 1;
                    break;
                } else if (map[nx][ny] == 3) {
                    res = min(res, step + 1);
                    break;
                }
                first = false;
            } else {
                break;
            }
        }
    }
}

int main() {
    while (cin >> n >> m && (m != 0 || n != 0)) {
        int sx = 0, sy = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> map[i][j];
                if (map[i][j] == 2) {
                    sx = i;
                    sy = j;
                }
            }
        }
        res = MAX_TIME;
        dfs(sx, sy, 0);
        if (res == MAX_TIME) {
            cout << -1 << endl;
        } else {
            cout << res << endl;
        }
    }
    return 0;
}
