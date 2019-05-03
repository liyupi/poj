// http://poj.org/problem?id=3672
#include <iostream>

using namespace std;

const int MAXN = 100001;
int M, T, U, F, D;
char c[MAXN];

int main() {
    while (~scanf("%d%d%d%d%d", &M, &T, &U, &F, &D)) {
        int res = 0;
        int sum = 0;
        for (int i = 0; i < T; ++i) {
            scanf("\n%c", &c[i]);
        }
        for (int i = 0; i < T; ++i) {
            switch (c[i]) {
                case 'u':
                    sum += U + D;
                    break;
                case 'f':
                    sum += 2 * F;
                    break;
                default:
                    sum += U + D;
            }
            if (sum > M) {
                break;
            }
            res++;
        }
        printf("%d\n", res);
    }
    return 0;
}