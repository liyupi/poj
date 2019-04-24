// http://poj.org/submit?problem_id=1274
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 201;
const int MAXM = 201;

int map[MAXN][MAXM];
int girls[MAXM];
int used[MAXM];

int N, M;

bool find(int man) {
    for (int i = 1; i <= M; ++i) {
        if (!used[i] && map[man][i]) {
            used[i] = 1;
            if (!girls[i] || find(girls[i])) {
                girls[i] = man;
                return true;
            }
        }
    }
    return false;
}

int main() {
    while(~scanf("%d%d", &N, &M)) {
        memset(map, 0, sizeof(map));
        memset(girls, 0, sizeof(girls));
        int num, pos;
        for (int i = 1; i <= N; ++i) {
            scanf("%d", &num);
            for (int j = 0; j < num; ++j) {
                scanf("%d", &pos);
                map[i][pos] = 1;
            }
        }
        int res = 0;
        for (int i = 1; i <= N; ++i) {
            memset(used, 0, sizeof(used));
            if (find(i)) {
                res++;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}