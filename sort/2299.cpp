// https://blog.csdn.net/alongela/article/details/8119209
// 最少交换次数=逆序对数，用归并排序可顺便求出
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 500001;

int nums[MAXN];
int tmp[MAXN];

int n;

long long ans;

void merge(int left, int mid, int right) {
    int i = left;
    int j = mid;
    int pos = left;
    while (i < mid && j < right) {
        if (nums[i] < nums[j]) {
            tmp[pos++] = nums[i++];
        } else {
            // 逆序数统计
            ans += j - pos;
            tmp[pos++] = nums[j++];
        }
    }
    while (i < mid) {
        tmp[pos++] = nums[i++];
    }
    while (j < right) {
        tmp[pos++] = nums[j++];
    }
    for (int k = left; k < right; ++k) {
        nums[k] = tmp[k];
    }
}


void mergeSort(int left, int right) {
    if (left == right - 1) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
}

int main() {
    while (cin >> n && n) {
        ans = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &nums[i]);
        }
        mergeSort(0, n);
        cout << ans << endl;
    }
    return 0;
}
