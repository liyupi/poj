// http://poj.org/problem?id=1573
#include <iostream>

using namespace std;

const int MAX = 15;
char map[MAX][MAX];
int visited[MAX][MAX];

int main() {
    int m, n, x, y;
    while (cin >> m >> n >> y) {
        if (m == 0 && n == 0 && y == 0) {
            return 0;
        }
        x = 0;
        y--;
        memset(visited, -1, sizeof(visited));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> map[i][j];
            }
        }
        int step = 0;
        bool exit = false;
        while (visited[x][y] == -1 && !exit) {
            visited[x][y] = step++;
            switch (map[x][y]) {
                case 'W':
                    y -= 1;
                    if (y < 0) {
                        exit = true;
                    }
                    break;
                case 'N' :
                    x -= 1;
                    if (x < 0) {
                        exit = true;
                    }
                    break;
                case 'S':
                    x += 1;
                    if (x == m) {
                        exit = true;
                    }
                    break;
                case 'E':
                    y += 1;
                    if (y == n) {
                        exit = true;
                    }
                    break;
                default:
                    break;
            }
        }
        if (exit) {
            printf("%d step(s) to exit\n", step);
        } else {
            printf("%d step(s) before a loop of %d step(s)\n", visited[x][y], step - visited[x][y]);
        }
    }
}