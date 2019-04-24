// https://www.cnblogs.com/star-eternal/p/7599133.html
// dijkstra次短路和最短路
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1001;
const int MAXM = 10111;

const int INF = 1000000005;

struct Edge {
    int to;
    int next;
    int dis;
} edges[MAXM];

// 邻接表头
int head[MAXN];
// 最短路与次短路更新
int used[MAXN][2];
// 最短路与次短路距离
int dis[MAXN][2];
// 到某个节点的最短路和次短路计数
int count[MAXN][2];

int start, final;

int N, M;

void dijkstra() {
    // 初始化
    memset(used, 0, sizeof(used));
    memset(count, 0, sizeof(count));
    for (int i = 1; i <= N; ++i) {
        dis[i][0] = dis[i][1] = INF;
    }
    dis[start][0] = 0;
    count[start][0] = 1;
    // 遍历节点集，N次用于次短路，N-1次用于最短路
    for (int i = 1; i < 2 * N; ++i) {
        int nowPos = INF;
        int minNum = INF;
        // 找到当前最小的节点
        // 更新的是最短路节点还是次短路节点
        int flag = 0;
        for (int j = 1; j <= N; ++j) {
            if (!used[j][0] && dis[j][0] < minNum) {
                nowPos = j;
                minNum = dis[j][0];
                flag = 0;
            } else if (!used[j][1] && dis[j][1] < minNum) {
                nowPos = j;
                minNum = dis[j][1];
                flag = 1;
            }
        }
        // 有节点未被连通，直接返回
        if (nowPos == INF) {
            return;
        }
        // 该节点被访问
        used[nowPos][flag] = 1;
        // 更新相邻节点（松弛）
        for (int j = head[nowPos]; j != -1; j = edges[j].next) {
            int newDis = minNum + edges[j].dis;
            int to = edges[j].to;
            // 核心
            // 比最短路短
            if (dis[to][0] > newDis) {
                dis[to][1] = dis[to][0];
                count[to][1] = count[to][0];
                dis[to][0] = newDis;
                count[to][0] = count[nowPos][flag];
            } else if (dis[to][0] == newDis) {
                // 等于最短路
                count[to][0] += count[nowPos][flag];
            } else if (dis[to][1] > newDis) {
                // 比次短路短
                dis[to][1] = newDis;
                count[to][1] = count[nowPos][flag];
            } else if (dis[to][1] == newDis) {
                // 等于次短路
                count[to][1] += count[nowPos][flag];
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(head, -1, sizeof(head));
        cin >> N >> M;
        int from, to, dist;
        for (int i = 0; i < M; ++i) {
            scanf("%d%d%d", &from, &to, &dist);
            edges[i].to = to;
            edges[i].dis = dist;
            edges[i].next = head[from];
            head[from] = i;
        }
        cin >> start >> final;
        dijkstra();
        cout << (dis[final][0] == dis[final][1] - 1 ? (count[final][0] + count[final][1]) : count[final][0]) << endl;
    }
    return 0;
}
