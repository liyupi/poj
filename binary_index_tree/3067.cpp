// https://blog.csdn.net/kkkkahlua/article/details/76785265
// 整道题就是逆序对，要先对数据进行排序，y坐标就相当于数组中的下标，x坐标相当于数组的值
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1001;
const int MAXK = 1010000;

int M, N, K;

struct Edge {
    int x;
    int y;
} edges[MAXK];

int C[MAXN];

int lowbit(int num) {
    return num & (-num);
}

int getSum(int index) {
    int sum = 0;
    while (index) {
        sum += C[index];
        index -= lowbit(index);
    }
    return sum;
}

void update(int index, int val) {
    while (index <= N) {
        C[index] += val;
        index += lowbit(index);
    }
}

bool cmp(const Edge &a, const Edge &b) {
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}

int main() {
    int t;
    cin >> t;
    int count = 0;
    while (t--) {
        memset(C, 0, sizeof(C));
        cin >> N >> M >> K;
        for (int i = 0; i < K; ++i) {
            scanf("%d%d", &edges[i].x, &edges[i].y);
        }
        sort(edges, edges + K, cmp);
        long long res = 0;
        for (int i = 0; i < K; ++i) {
            update(edges[i].x, 1);
            res += i + 1 - getSum(edges[i].x);
        }
        printf("Test case %d: %lld\n", ++count, res);
    }
    return 0;
}
