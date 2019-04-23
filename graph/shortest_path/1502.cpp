// http://poj.org/problem?spm=a2c4e.11153940.blogcont9125.5.73ce41a3onmgA9&id=1502
#include <iostream>

using namespace std;

const int MAXN = 101;
const int INF = 1000000;

int edge[MAXN][MAXN];
int N;
int used[MAXN];
int dis[MAXN];

int dijkstra() {
    for (int i = 1; i <= N; ++i) {
        dis[i] = INF;
    }
    dis[1] = 0;
    int nowPos = 1;
    int minNum;
    // 共更新N - 1轮
    for (int i = 1; i <= N - 1; ++i) {
        minNum = INF;
        int minPos = 0;
        used[nowPos] = 1;
        for (int j = 1; j <= N; ++j) {
            if (!used[j] && edge[nowPos][j] != INF) {
                dis[j] = min(dis[j], dis[nowPos] + edge[nowPos][j]);
                if (dis[j] < minNum) {
                    minNum = dis[j];
                    minPos = j;
                }
            }
        }
        nowPos = minPos;
    }
    int maxNum = 0;
    for (int i = 2; i <= N; ++i) {
        maxNum = max(maxNum, dis[i]);
    }
    return maxNum;
}

int main() {
    while (cin >> N) {
        char str[10];
        // 输入
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= i; ++j) {
                if (i == j) {
                    edge[i][j] = 0;
                } else {
                    scanf("%s", str);
                    if (str[0] == 'x') {
                        edge[i][j] = INF;
                    } else {
                        edge[i][j] = atoi(str);
                    }
                }
            }
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                edge[i][j] = edge[j][i];
            }
        }
        cout << dijkstra() << endl;

    }
    return 0;
}