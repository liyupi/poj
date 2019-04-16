// http://poj.org/problem?id=2388
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1000001;

int bucket[MAXN] = {0};

int n, num;

/**
 * 桶排序（79ms）
 */
void bucketSort() {
    for (int i = 0; i < n; ++i) {
        cin >> num;
        bucket[num]++;
    }
    int i = 0;
    int j = 0;
    n /= 2;
    while (i <= n) {
        while (!bucket[j]) {
            j++;
        }
        i += bucket[j];
        j++;
    }
    cout << j - 1 << endl;
}

/**
 * 快排
 */
void quickSort() {
    for (int i = 0; i < n; ++i) {
        cin >> bucket[i];
    }
    sort(bucket, bucket + n);
    cout << bucket[n / 2] << endl;
}

int main() {
    cin >> n;
//    bucketSort();
    quickSort();
    return 0;
}
