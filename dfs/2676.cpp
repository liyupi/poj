// http://poj.org/problem?id=2676
// 很简单的题，一开始数组第二维开小了
#include <iostream>

using namespace std;

int map[9][9];

// 判断每一行第i个数是否已使用
int row[9][10] = {0};
// 判断每一列第i个数是否已使用
int col[9][10] = {0};
// 判断每一个9宫格第i个数是否已使用
int box[9][10] = {0};

bool dfs(int x, int y) {
    if (x == 9) {
        return true;
    }
    if (y == 9) {
        return dfs(x + 1, 0);
    }
    if (map[x][y]) {
        return dfs(x, y + 1);
    }
    // 尝试填数
    int boxNum = 3 * (x / 3) + y / 3;
    for (int i = 1; i <= 9; ++i) {
        if (!row[x][i] && !col[y][i] && !box[boxNum][i]) {
            row[x][i] = 1;
            col[y][i] = 1;
            box[boxNum][i] = 1;
            map[x][y] = i;
            if (dfs(x, y + 1)) {
                return true;
            }
            // 回溯
            row[x][i] = 0;
            col[y][i] = 0;
            box[boxNum][i] = 0;
            map[x][y] = 0;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        // reset
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(box, 0, sizeof(box));
        for (int i = 0; i < 9; ++i) {
            getchar();
            for (int j = 0; j < 9; ++j) {
                char c;
                scanf("%c", &c);
                map[i][j] = c - 48;
                if (map[i][j]) {
                    row[i][map[i][j]] = 1;
                    col[j][map[i][j]] = 1;
                    box[3 * (i / 3) + j / 3][map[i][j]] = 1;
                }
            }
        }
        dfs(0, 0);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                printf("%d", map[i][j]);
            }
            printf("\n");
        }

    }
    return 0;
}
