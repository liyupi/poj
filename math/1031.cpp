// http://poj.org/problem?id=1031
// 恶心的公式题
#include <iostream>
#include <cmath>

#define PI 3.141592657
using namespace std;

const int MAXN = 101;

double pos[MAXN][2];

double getRad(double x1, double y1, double x2, double y2) {
    double a = atan2(y1, x1);
    double b = atan2(y2, x2);
    if (b - a > PI) {
        a += 2 * PI;
    }
    if (a - b > PI) {
        b += 2 * PI;
    }
    return a - b;
}

int main() {
    double k, h;
    int N;
    scanf("%lf%lf%d", &k, &h, &N);
    for (int i = 0; i < N; ++i) {
        scanf("%lf%lf", &pos[i][0], &pos[i][1]);
    }
    pos[N][0] = pos[0][0];
    pos[N][1] = pos[0][1];
    double minNum = 0;
    double maxNum = 0;
    double sum = 0;
    for (int i = 0; i < N; ++i) {
        double rad = getRad(pos[i][0], pos[i][1], pos[i + 1][0], pos[i + 1][1]);
        sum += rad;
        minNum = min(minNum, sum);
        maxNum = max(maxNum, sum);
        if (maxNum - minNum >= 2 * PI) {
            maxNum = minNum + 2 * PI;
            break;
        }
    }
    printf("%.2lf\n", k * h * (maxNum - minNum));
}

