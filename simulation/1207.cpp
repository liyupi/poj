// https://blog.csdn.net/mdd18703649811/article/details/54912793
// 模拟即可，想复杂了
#include <iostream>

using namespace std;

int getCount(int num) {
    int count = 1;
    while (num != 1) {
        if (num & 1) {
            num = 3 * num + 1;
        } else {
            num /= 2;
        }
        count++;
    }
    return count;
}

int main() {
    int a, b;
    while (~scanf("%d%d", &a, &b)) {
        int res = 0;
        if  (a <= b) {
            for (int i = a; i <= b; ++i) {
                res = max(getCount(i), res);
            }
        } else {
            for (int i = b; i <= a; ++i) {
                res = max(getCount(i), res);
            }
        }
        printf("%d %d %d\n", a, b, res);
    }
    return 0;
}