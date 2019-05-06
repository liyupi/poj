// https://www.bbsmax.com/A/MyJxAx3e5n/
#include <iostream>

using namespace std;

const int MAXN = 4002;

int parent[MAXN];

void init() {
    for (int i = 1; i < MAXN; ++i) {
        parent[i] = i;
    }
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

bool unionSet(int a, int b) {
    int i = find(a);
    int j = find(b);
    if (i == j) {
        return false;
    }
    parent[j] = i;
    return true;
}

int N, M;

int main() {
    int T;
    scanf("%d", &T);
    int count = 0;
    while (T--) {
        if (count) {
            printf("\n");
        }
        init();
        bool flag = true;
        scanf("%d%d", &N, &M);
        int a, b;
        for (int i = 0; i < M; ++i) {
            scanf("%d%d", &a, &b);
            if (!flag) {
                continue;
            }
            if (find(a) == find(b)) {
                flag = false;
            }
            unionSet(a, b + N);
            unionSet(b, a + N);
        }
        printf("Scenario #%d:\n", ++count);
        if (flag) {
            printf("No suspicious bugs found!\n");
        } else {
            printf("Suspicious bugs found!\n");
        }
    }
    return 0;
}