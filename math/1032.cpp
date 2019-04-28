// http://poj.org/problem?id=1032
#include <iostream>

using namespace std;

int main() {
    int n;
    while (~scanf("%d", &n)) {
        int sum = 0;
        int i = 2;
        while (sum + i < n) {
            sum += i++;
        }
        int left = n - sum;
        if (left == i) {
            for (int j = 2; j < i; ++j) {
                printf("%d ", j);
            }
            printf("%d\n", i);
        } else {
            i--;
            int moreNum = i - left;
            for (int j = 2; j < i; ++j) {
                printf("%d ", j + (j > moreNum));
            }
            printf("%d\n", i + (i > moreNum) + !moreNum);
        }
    }
    return 0;
}