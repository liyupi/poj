// http://poj.org/problem?id=3086
#include <iostream>

using namespace std;

const int MAXN = 1001;
int T[MAXN + 1];
long long W[MAXN];

int N;

void init() {
    for (int i = 1; i <= MAXN; ++i) {
        T[i] = T[i - 1] + i;
    }
    for (int k = 1; k < MAXN; ++k) {
        W[k] = W[k - 1] + k * T[k + 1];
    }
}

int main() {
    init();
    cin >> N;
    int n;
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &n);
        printf("%d %d %lld\n", i, n, W[n]);
    }
    return 0;
}