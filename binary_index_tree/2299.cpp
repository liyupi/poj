// https://blog.csdn.net/Small_Orange_glory/article/details/81290634
// 树状数组求逆序对
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

const int MAXN = 500001;

int n;
int a[MAXN];
int b[MAXN];
map<int, int> mmap;

int lowbit(int num) {
    return num & (-num);
}

void update(int index, int val) {
    while (index <= n) {
        a[index] += val;
        index += lowbit(index);
    }
}

int getSum(int index) {
    int sum = 0;
    while (index) {
        sum += a[index];
        index -= lowbit(index);
    }
    return sum;
}

int main() {
    while (cin >> n && n) {
        mmap.clear();
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            mmap[a[i]] = i;
        }
        sort(a + 1, a + n + 1);
        // 离散化
        for (int i = 1; i <= n; i++) {
            b[i] = mmap[a[i]];
        }
        memset(a, 0, sizeof(a));
        long long res = 0;
        for (int i = 1; i <= n; ++i) {
            update(b[i], 1);
            res += i - getSum(b[i]);
        }
        cout << res << endl;
    }
    return 0;
}
