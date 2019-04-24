// https://blog.csdn.net/zhang20072844/article/details/7761273
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 201;
const int INF = 0x3f3f3f3f;

int N, from, to;

int map[MAXN][MAXN];
int dis[MAXN];
int used[MAXN];

int dijkstra() {
    for (int i = 1; i <= N; ++i) {
        dis[i] = INF;
    }
    memset(used, 0, sizeof(used));
    dis[from] = 0;
    for (int i = 0; i < N - 1; ++i) {
        int minPos = INF;
        int minNum = INF;
        for (int j = 1; j <= N; ++j) {
            if (!used[j] && dis[j] < minNum) {
                minPos = j;
                minNum = dis[j];
            }
        }
        if (minNum == INF) {
            return dis[to];
        }
        used[minPos] = 1;
        for (int j = 1; j <= N; ++j) {
            if (!used[j] && map[minPos][j] != INF) {
                dis[j] = min(dis[j], minNum + map[minPos][j]);
            }
        }
    }
    return dis[to];
}

int main() {
    while (~scanf("%d%d%d", &N, &from, &to)) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                map[i][j] = i == j ? 0 : INF;
            }
        }
        int num, tmp;
        for (int i = 1; i <= N; ++i) {
            scanf("%d", &num);
            for (int j = 0; j < num; ++j) {
                scanf("%d", &tmp);
                map[i][tmp] = j == 0 ? 0 : 1;
            }
        }
        printf("%d\n", dijkstra() == INF ? -1 : dis[to]);
    }
    return 0;
}