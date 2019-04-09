// http://poj.org/problem?id=1416
// 最小覆盖数
#include <iostream>
#include <cstring>

using namespace std;

int N, K;

int map[501][501];
int used[501];
int girls[501] = {0};

bool find(int m) {
    for (int j = 1; j <= N; ++j) {
        if (map[m][j] && !used[j]) {
            used[j] = 1;
            if (!girls[j] || find(girls[j])) {
                girls[j] = m;
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> N >> K;
    for (int i = 1; i <= K; ++i) {
        int m, n;
        cin >> m >> n;
        map[m][n] = 1;
    }
    int res = 0;
    // 给每个男生找妹子
    for (int i = 1; i <= N; ++i) {
        memset(used, 0, sizeof(used));
        if (find(i)) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}
