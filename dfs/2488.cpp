// https://www.cnblogs.com/llhthinker/p/4924654.html
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int dir[][2] = {{-1, -2},
                      {1,  -2},
                      {-2, -1},
                      {2,  -1},
                      {-2, 1},
                      {2,  1},
                      {-1, 2},
                      {1,  2}};

int visited[27][27] = {0};
int p, q, num;

int pathX[27];
int pathY[27];

bool dfs(int x, int y, int count) {
    pathY[count] = y + 64;
    pathX[count] = x;
    if (count == num) {
        return true;
    }
    bool flag = false;
    for (int i = 0; i < 8; ++i) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx >= 1 && ny >= 1 && nx <= p && ny <= q && !visited[nx][ny]) {
            visited[nx][ny] = 1;
            flag = dfs(nx, ny, count + 1);
            visited[nx][ny] = 0;
            if (flag) {
                break;
            }
        }
    }
    return flag;
}

int main() {
    int t;
    int count = 1;
    cin >> t;
    while (t--) {
        cin >> p >> q;
        num = p * q;
        visited[1][1] = 1;
        bool flag = dfs(1, 1, 1);
        visited[1][1] = 0;
        printf("Scenario #%d:\n", count++);
        if (flag) {
            for (int i = 1; i <= num; ++i) {
                printf("%c%d", pathY[i], pathX[i]);
            }
        } else {
            printf("impossible");
        }
        if (t != 0) {
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
