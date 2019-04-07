// http://poj.org/problem?id=3006
#include <iostream>

using namespace std;

const int MAXN = 1000001;

int notPrime[MAXN] = {0};

void init() {
    notPrime[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        if (!notPrime[i]) {
            int j = 2;
            int num = i * j;
            while (num < MAXN) {
                notPrime[num] = 1;
                j++;
                num = i * j;
            }
        }
    }
}

int main() {
    init();
    int a, d, n;
    while (cin >> a >> d >> n) {
        if (!a && !d && !n) {
            break;
        }
        while (n--) {
            while (notPrime[a]) {
                a += d;
            }
            a += d;
        }
        cout << a - d << endl;
    }
    return 0;
}
