// https://www.cnblogs.com/jin-nuo/p/5297963.html
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
    double VS, R, C;
    int t;
    scanf("%lf%lf%lf%d", &VS, &R, &C, &t);
    while (t--) {
        double w;
        scanf("%lf", &w);
        printf("%.3lf\n", R * C * w * VS * sqrt(1 / (R * R * C * C * w * w + 1)));
    }
    return 0;
}