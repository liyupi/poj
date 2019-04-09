// http://poj.org/problem?id=2231
// 可自己推演出公式，如果不是递增数列，规律将被打乱
#include <iostream>
#include <algorithm>

using namespace std;

// 必须为long long，否则会丢失位数
long long nums[100001];

int main() {
    int n;
    while (cin >> n) {
        long long res = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &nums[i]);
        }
        sort(nums + 1, nums + n + 1);
        int j;
        for (int i = 1; i < n; ++i) {
            j = n - i;
            res += j * (nums[j + 1] - nums[i]);
        }
        cout << res * 2 << endl;
    }
    return 0;
}