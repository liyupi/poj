// https://blog.csdn.net/u013476556/article/details/30781771
#include <iostream>
#include <string>


using namespace std;

int map[4][4];

const int INF = 999999;

int ans = INF;

/**
 * 判断是否满足条件
 * @return
 */
bool judge() {
    int num = map[0][0];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (map[i][j] != num) {
                return false;
            }
        }
    }
    return true;
}

/**
 * 翻转
 * @param x
 * @param y
 */
void flip(int x, int y) {
    map[x][y] = !map[x][y];
    if (x - 1 >= 0) {
        map[x - 1][y] = !map[x - 1][y];
    }
    if (y - 1 >= 0) {
        map[x][y - 1] = !map[x][y - 1];
    }
    if (x + 1 < 4) {
        map[x + 1][y] = !map[x + 1][y];
    }
    if (y + 1 < 4) {
        map[x][y + 1] = !map[x][y + 1];
    }
}

void dfs(int x, int y, int count) {
    if (judge()) {
        if (count < ans) {
            ans = count;
        }
        return;
    }
    if (x >= 4 || y >= 4) {
        return;
    }
    int nx = (x + 1) % 4;
    int ny = y + (x + 1) / 4;
    dfs(nx, ny, count);
    flip(x, y);
    dfs(nx, ny, count + 1);
    // 回溯
    flip(x, y);
}

int main() {
    string str;
    for (int i = 0; i < 4; ++i) {
        cin >> str;
        for (int j = 0; j < 4; ++j) {
            if (str[j] == 'w') {
                map[i][j] = 1;
            } else {
                map[i][j] = 0;
            }
        }
    }
    dfs(0, 0, 0);
    if (ans == INF) {
        cout << "Impossible" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}