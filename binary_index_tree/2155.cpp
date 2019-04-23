// https://blog.csdn.net/acm_fish/article/details/69842523
// 二维树状数组模板题，本意是单点查询、区间修改，可转换为单点修改，区间求和
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1001;

int C[MAXN][MAXN];

int lowbits[MAXN];

int N, num;
char c;

void update(int x, int y, int val) {
    for (int i = x; i < MAXN; i+=lowbits[i]) {
        for (int j = y; j < MAXN; j+=lowbits[j]) {
            C[i][j] += val;
        }
    }
}

int getSum(int x, int y) {
    int sum = 0;
    for (int i = x; i > 0; i-=lowbits[i]) {
        for (int j = y; j > 0; j-=lowbits[j]) {
            sum += C[i][j];
        }
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i < MAXN; ++i) {
        lowbits[i] = i &(-i);
    }
    while(t--) {
        memset(C, 0, sizeof(C));
        scanf("%d%d", &N, &num);
        int x1, y1, x2, y2;
        for (int i = 0; i < num; ++i) {
            getchar();
            scanf("%c", &c);
            if (c == 'C') {
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                update(x1, y1, 1);
                update(x2 + 1, y2 + 1, 1);
                update(x1, y2 + 1, 1);
                update(x2 + 1, y1, 1);
            } else {
                scanf("%d%d", &x1, &y1);
                printf("%d\n", getSum(x1, y1) % 2);
            }
        }
        printf("\n");
    }

    return 0;
}
