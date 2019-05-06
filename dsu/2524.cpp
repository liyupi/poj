// http://poj.org/problem?id=2524
#include <iostream>

using namespace std;

const int MAXN = 50001;

int parent[MAXN];

int N, M;
int count;

void init();

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionSet(int a, int b) {
    int i = find(a);
    int j = find(b);
    if (i != j) {
        count--;
        parent[j] = i;
    }
}

int main() {
    int a, b;
    int t = 0;
    while (~scanf("%d%d", &N, &M) && (N != 0 || M != 0)) {
        init();
        count = N;
        for (int i = 0; i < M; ++i) {
            scanf("%d%d", &a, &b);
            unionSet(a, b);
        }
        printf("Case %d: %d\n", ++t, count);
    }
}

void init() {
    for (int i = 1; i < MAXN; ++i) {
        parent[i] = i;
    }
}