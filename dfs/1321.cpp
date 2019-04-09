// http://poj.org/problem?id=1321
#include <iostream>

using namespace std;

int n, k;

char map[8][8];

int vy[8] = {0};

int dfs(int x, int num) {
    // 从第0行开始
    if (x == n) {
        if (num == k) {
            return 1;
        }
        return 0;
    }
    int sum = 0;
    // 摆在当前行第j列
    for (int j = 0; j < n; j++) {
        if (!vy[j] && map[x][j] == '#') {
            vy[j] = 1;
            sum += dfs(x + 1, num + 1);
            vy[j] = 0;
        }
    }
    // 当前行可以不摆放
    if (k - num < n - x) {
        sum += dfs(x + 1, num);
    }
    return sum;
}

int main() {
    while (cin >> n >> k && (n != -1 || k != -1)) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> map[i][j];
            }
        }
        cout << dfs(0, 0) << endl;
    }
    return 0;
}