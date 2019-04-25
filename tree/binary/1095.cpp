// https://www.cnblogs.com/jin-nuo/p/5297963.html
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int N;

long long ctl[21];

void init() {
    // 卡特兰数
    ctl[0] = 1;
    for (int i = 1; i <= 20; ++i) {
        ctl[i] = ctl[i - 1] * (4 * i - 2) / (i + 1);
    }
}

void build(int k, int cnt) {
    if (k == 1) {
        printf("X");
        return;
    }
    if (cnt <= ctl[k - 1]) {
        // 只有右子树
        printf("X(");
        build(k - 1, cnt);
        printf(")");
    } else if (cnt > ctl[k] - ctl[k - 1]) {
        // 只有左子树
        printf("(");
        build(k - 1, cnt - ctl[k] + ctl[k - 1]);
        printf(")X");
    } else {
        // 判断左右子树节点数
        int total = k - 1;
        int rightNum;
        // 按右子树节点依次减少的次序求节点数
        // 从total开始，因为要先减去只有右子树的情况
        for (int i = total; i > 0; i--) {
            if (ctl[i] * ctl[total - i] < cnt) {
                cnt -= ctl[i] * ctl[total - i];
            } else {
                rightNum = i;
                break;
            }
        }
        printf("(");
        // 右子树权值大，左子树权值小
        build(total - rightNum, cnt / ctl[rightNum] + (cnt % ctl[rightNum] != 0));
        printf(")X(");
        build(rightNum, (cnt - 1) % ctl[rightNum] + 1);
        printf(")");
    }
}

int main() {
    init();
     while (~scanf("%d", &N) && N) {
        int i = 1;
        while (N > ctl[i]) {
            N -= ctl[i++];
        }
        build(i, N);
        printf("\n");
    }
    return 0;
}