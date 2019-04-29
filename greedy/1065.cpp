// https://blog.csdn.net/niushuai666/article/details/6419922
// 贪心
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 5001;

struct Pair {
    int l;
    int w;
} pairs[MAXN];

bool used[MAXN];

int N;

bool cmp(const Pair &pair1, const Pair &pair2) {
    if (pair1.l != pair2.l) {
        return pair1.l < pair2.l;
    }
    return pair1.w < pair2.w;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            scanf("%d%d", &pairs[i].w, &pairs[i].l);
        }
        memset(used, 0, sizeof(used));
        sort(pairs, pairs + N, cmp);
        int res = 0;
        int pos = 0;
        while (true) {
            res++;
            int nextPos = 0;
            for (int i = pos + 1; i < N; ++i) {
                if (used[i]) {
                    continue;
                }
                if (pairs[i].w < pairs[pos].w) {
                    if (!nextPos) {
                        nextPos = i;
                    }
                } else {
                    used[i] = true;
                    pos = i;
                }
            }
            pos = nextPos;
            if (!pos) {
                break;
            }
        }
        printf("%d\n", res);
    }
}

