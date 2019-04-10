// http://poj.org/problem?id=3349
// 设计hash，记个素数99991
#include <iostream>

using namespace std;

const int MAXN = 100001;
const int BIG_PRIME = 99991;

int snows[MAXN][6];

int map[BIG_PRIME][5];

int n;

int getHash(int i) {
    int sum = 0;
    for (int j = 0; j < 6; ++j) {
        sum += snows[i][j] % BIG_PRIME;
    }
    return sum % BIG_PRIME;
}

bool same(int a, int b) {
    // 雪花1开始坐标始终为0，雪花2开始坐标从0-5
    for (int i = 0; i < 6; i++) {
        // 正旋
        for (int k = 0; k < 6; ++k) {
            if (snows[a][k % 6] != snows[b][(i + k) % 6]) {
                break;
            }
            if (k == 5) {
                return true;
            }
        }
        // 逆旋
        for (int k = 0; k < 6; ++k) {
            if (snows[a][k % 6] != snows[b][(i - k + 6) % 6]) {
                break;
            }
            if (k == 5) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n;
    memset(map, 0, sizeof(map));
    bool find = false;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 6; ++j) {
            scanf("%d", &snows[i][j]);
        }
        if (!find) {
            int hash = getHash(i);
            int k = 0;
            while (map[hash][k]) {
                if (same(i, map[hash][k])) {
                    find = true;
                    break;
                }
                k++;
            }
            map[hash][k] = i;
        }
    }
    if (find) {
        cout << "Twin snowflakes found." << endl;
    } else {
        cout << "No two snowflakes are alike." << endl;
    }

}
