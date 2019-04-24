// https://blog.csdn.net/neighthorn/article/details/51077689
// 拓扑排序模板
#include <iostream>
#include <set>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 101;

int N;
int used[MAXN];

// 记录每个节点的父节点邻接表
set<int> parentNodes[MAXN];

int main() {
    while (~scanf("%d", &N)) {
        memset(used, 0, sizeof(used));
        int child;
        for (int i = 1; i <= N; ++i) {
            while (scanf("%d", &child) && child) {
                parentNodes[child].insert(i);
            }
        }
        // 拓扑排序
        queue<int> queue;
        // 找入度为0的点
        for (int i = 1; i <= N; ++i) {
            if (parentNodes[i].empty()) {
                queue.push(i);
                used[i] = 1;
            }
        }
        while (!queue.empty()) {
            int node = queue.front();
            printf("%d ", node);
            queue.pop();
            // 更新相邻节点的入度
            for (int i = 1; i <= N; ++i) {
                parentNodes[i].erase(node);
                if (!used[i] && parentNodes[i].empty()) {
                    queue.push(i);
                    used[i] = 1;
                }
            }
        }
        printf("\n");
    }
    return 0;
}


