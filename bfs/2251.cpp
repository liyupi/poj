// http://poj.org/problem?id=2251
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int l, r, c;

char map[31][31][31];

int visited[31][31][31];

const int dirs[][3] = {{1,  0,  0},
                       {-1, 0,  0},
                       {0,  1,  0},
                       {0,  -1, 0},
                       {0,  0,  1},
                       {0,  0,  -1}};

struct Pos {
    int x;
    int y;
    int z;
} from;


int bfs() {
    queue<Pos> queue;
    queue.push(from);
    int count = 0;
    while (!queue.empty()) {
        count++;
        int size = queue.size();
        for (int i = 0; i < size; ++i) {
            Pos pos = queue.front();
            queue.pop();
            int nx, ny, nz;
            for (int j = 0; j < 6; ++j) {
                nx = pos.x + dirs[j][0];
                ny = pos.y + dirs[j][1];
                nz = pos.z + dirs[j][2];
                if (nx >= 0 && ny >= 0 && nz >= 0 && nx < l && ny < r && nz < c && map[nx][ny][nz] != '#' &&
                    !visited[nx][ny][nz]) {
                    if (map[nx][ny][nz] == 'E') {
                        return count;
                    }
                    visited[nx][ny][nz] = 1;
                    Pos tmp = {nx, ny, nz};
                    queue.push(tmp);
                }
            }
        }
    }
    return -1;
}

int main() {
    while (cin >> l >> r >> c && (l || r || c)) {
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < r; ++j) {
                for (int k = 0; k < c; ++k) {
                    cin >> map[i][j][k];
                    if (map[i][j][k] == 'S') {
                        from.x = i;
                        from.y = j;
                        from.z = k;
                        visited[i][j][k] = 1;
                    }
                }
            }
        }
        int res = bfs();
        if (res != -1) {
            cout << "Escaped in " << res << " minute(s)." << endl;
        } else {
            cout << "Trapped!" << endl;
        }
    }
    return 0;
}