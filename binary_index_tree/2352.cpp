// https://blog.csdn.net/kkkkahlua/article/details/76785265
// 树状数组模板题，区间求和，a[i]表示数i的个数
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 32001;
const int MAX_LEVEL = 15001;

int c[MAXN] = {0};
int level[MAX_LEVEL] = {0};

int n;

int lowbit(int num) {
    return num & (-num);
}

void update(int index, int val) {
    while (index <= MAXN) {
        c[index] += val;
        index += lowbit(index);
    }
}

int getSum(int index) {
    int sum = 0;
    while (index) {
        sum += c[index];
        index -= lowbit(index);
    }
    return sum;
}

int main() {
    cin >> n;
    int x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        update(x++, 1);
        level[getSum(x)]++;
    }
    for (int i = 1; i <= n; ++i) {
        cout << level[i] << endl;
    }
    return 0;
}
