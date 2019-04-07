// https://www.cnblogs.com/shenben/p/5628296.html
// 方向太恶心了
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 41;
// 上右下左
int lDirs[][2] = {{0,  -1},
                       {1,  0},
                       {0,  1},
                       {-1, 0}};
// 上左下右
int rDirs[][2] = {{0,  -1},
                        {-1,  0},
                        {0,  1},
                        {1, 0}};
char map[MAXN][MAXN];
int visited[MAXN][MAXN];
int w, h;

struct Pos {
    int x;
    int y;
} start, to;

int dfs(int x, int y, int d, int count, int dirs[][2]) {
    for (int i = 0; i < 4; ++i) {
        int dir = ((d - 1 + 4) % 4 + i) % 4;
        int nx = x + dirs[dir][0];
        int ny = y + dirs[dir][1];
        if (nx == to.x && ny == to.y) {
            return count + 1;
        }
        if (nx >= 0 && nx < w && ny >= 0 && ny < h && map[ny][nx] != '#') {
            return dfs(nx, ny, dir, count + 1, dirs);
        }
    }
}

int bfs() {
    queue<Pos> queue;
    queue.push(start);
    int res = 1;
    while (true) {
        res++;
        int size = queue.size();
        for (int i = 0; i < size; ++i) {
            Pos tmp = queue.front();
            queue.pop();
            for (int j = 0; j < 4; ++j) {
                int nx = tmp.x + lDirs[j][0];
                int ny = tmp.y + lDirs[j][1];
                if (nx >= 0 && nx < w && ny >= 0 && ny < h && map[ny][nx] != '#' && !visited[ny][nx]) {
                    visited[ny][nx] = 1;
                    if (nx == to.x && ny == to.y) {
                        return res;
                    }
                    Pos pos;
                    pos.x = nx;
                    pos.y = ny;
                    queue.push(pos);
                }
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> w >> h;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> map[i][j];
                if (map[i][j] == 'S') {
                    start.x = j;
                    start.y = i;
                    visited[start.y][start.x] = 1;
                } else if (map[i][j] == 'E') {
                    to.x = j;
                    to.y = i;
                }
            }
        }
        int dir1, dir2;
        if (start.x == 0) {
            dir1 = 2;
            dir2 = 3;
        } else if (start.y == 0) {
            dir1 = dir2 = 2;
        } else if (start.x == w - 1) {
            dir1 = 3;
            dir2 = 2;
        } else {
            dir1 = dir2 = 0;
        }
        printf("%d %d %d\n", dfs(start.x, start.y, dir1, 1, lDirs), dfs(start.x, start.y, dir2, 1, rDirs), bfs());
    }
    return 0;
}
