// http://poj.org/problem?id=1046
#include <iostream>

using namespace std;

const int INF = 0x3f3f3f3f;

int colors[16][3];

int getDistance(int r, int g, int b, int r1, int g1, int b1) {
    return (r - r1) * (r - r1) + (g - g1) * (g - g1) + (b - b1) * (b - b1);
}

int main() {
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &colors[i][j]);
        }
    }
    int r, g, b;
    while (scanf("%d%d%d", &r, &g, &b) && (r != -1 || g != -1 || b != -1)) {
        int minNum = INF;
        int minPos = 0;
        for (int i = 0; i < 16; ++i) {
            int dis = getDistance(r, g, b, colors[i][0], colors[i][1], colors[i][2]);
            if (minNum > dis) {
                minNum = dis;
                minPos = i;
            }
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n", r, g, b, colors[minPos][0], colors[minPos][1], colors[minPos][2]);
    }
    return 0;
}


