// https://www.cnblogs.com/hrlnw/archive/2013/03/10/2953151.html
// 滑动窗口
#include <iostream>

using namespace std;

const int MAXN = 10001;

int notPrime[MAXN] = {0};

int primes[MAXN] = {0};

void init() {
    for (int i = 2; i < MAXN; ++i) {
        if (!notPrime[i]) {
            int j = 2;
            int num = j * i;
            while (num < MAXN) {
                notPrime[num] = 1;
                num = ++j * i;
            }
        }
    }
    int j = 0;
    for (int i = 2; i < MAXN; ++i) {
        if (!notPrime[i]) {
            primes[j++] = i;
        }
    }
}

int main() {
    init();
    int n;
    while (cin >> n) {
        if (!n) {
            return 0;
        }
        int sum = primes[0];
        int left = 0, right = 0;
        int res = 0;

        while (left <= right) {
            if (sum > n) {
                sum -= primes[left];
                left++;
            } else {
                if (sum == n) {
                    res++;
                }
                sum += primes[++right];
            }
        }
        cout << res << endl;
    }
}
