// http://poj.org/problem?id=1833
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1025;

const int fact[5] = {1, 1, 2, 6, 24};

int nums[MAXN];
int n, k;

void reverse() {
    int left = 0;
    int right = n - 1;
    while (left < right) {
        swap(left, right);
        left++;
        right--;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &nums[i]);
        }
        if (n < 5) {
            k %= fact[n];
        }
        while (k && next_permutation(nums, nums + n)) {
            k--;
        }
        if (k) {
            reverse();
            while (--k) {
                next_permutation(nums, nums + n);
            }
        }
        for (int i = 0; i < n - 1; ++i) {
            printf("%d ", nums[i]);
        }
        printf("%d\n", nums[n - 1]);
    }
}

