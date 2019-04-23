// https://blog.csdn.net/u011026968/article/details/38533289
// 二维树状数组模板题，区间求和
#include <iostream>
#include <cstring>

using namespace std;

const int MAXS = 1025;

long long C[MAXS][MAXS];

int lowbits[MAXS];

int S, X, Y, A, L, B, R, T;

void init() {
    cin >> S;
    memset(C, 0, sizeof(C));
    for (int i = 1; i <= S; ++i) {
        lowbits[i] = i & (-i);
    }
}

void update(int x, int y, int val) {
    for (int i = x; i <= S; i += lowbits[i]) {
        for (int j = y; j <= S; j += lowbits[j]) {
            C[i][j] += val;
        }
    }
}

long long getSum(int x, int y) {
    long long sum = 0;
    for (int i = x; i > 0; i -= lowbits[i]) {
        for (int j = y; j > 0; j -= lowbits[j]) {
            sum += C[i][j];
        }
    }
    return sum;
}

int main() {
    int func;
    while (cin >> func) {
        switch (func) {
            case 0:
                init();
                break;
            case 1:
                scanf("%d%d%d", &X, &Y, &A);
                update(X + 1, Y + 1, A);
                break;
            case 2:
                scanf("%d%d%d%d", &L, &B, &R, &T);
                cout << getSum(R + 1, T + 1) + getSum(L, B) - getSum(L, T + 1) - getSum(R + 1, B) << endl;
                break;
            default:
                return 0;
        }
    }
    return 0;
}
