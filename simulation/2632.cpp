// https://blog.csdn.net/lyy289065406/article/details/6645428
#include <iostream>

using namespace std;

const int dirs[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

struct Robot {
    int x, y, dir;
} robots[101];

// 存储机器人数
int map[101][101];

int A, B, rNum, iNum;

bool doAction(int id, char action, int repeat) {
    Robot *robot = &robots[id];
    switch (action) {
        case 'L':
            robot->dir = (robot->dir + repeat % 4) % 4;
            break;
        case 'R':
            robot->dir = (robot->dir + 4 - repeat % 4) % 4;
            break;
        default:
            while (repeat--) {
                map[robot->x][robot->y] = 0;
                robot->x += dirs[robot->dir][0];
                robot->y += dirs[robot->dir][1];
                if (map[robot->x][robot->y]) {
                    printf("Robot %d crashes into robot %d\n", id, map[robot->x][robot->y]);
                    return true;
                } else {
                    map[robot->x][robot->y] = id;
                }
                if (robot->x == 0 || robot->x == A + 1 || robot->y == 0 || robot->y == B + 1) {
                    printf("Robot %d crashes into the wall\n", id);
                    return true;
                }
            }
            break;
    }
    return false;
}

int main() {
    int t;
    while (cin >> t) {
        while (t--) {
            memset(map, 0, sizeof(map));
            cin >> A >> B >> rNum >> iNum;
            char c;
            for (int i = 1; i <= rNum; ++i) {
                cin >> robots[i].x >> robots[i].y >> c;
                map[robots[i].x][robots[i].y] = i;
                switch (c) {
                    case 'E':
                        robots[i].dir = 0;
                        break;
                    case 'N':
                        robots[i].dir = 1;
                        break;
                    case 'W':
                        robots[i].dir = 2;
                        break;
                    case 'S':
                        robots[i].dir = 3;
                        break;
                    default:
                        break;
                }
            }
            int id, repeat;
            char action;
            bool crashed = false;
            for (int i = 0; i < iNum; ++i) {
                cin >> id >> action >> repeat;
                // 相撞后不再计算
                if (!crashed) {
                    crashed = doAction(id, action, repeat);
                }
            }
            if (!crashed) {
                printf("OK\n");
            }
        }

    }
}