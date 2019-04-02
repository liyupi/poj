// https://cavenkaka.iteye.com/blog/1623400
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
    double left;
    double right;
} points[1200];

bool cmp(const Point &p1, const Point &p2) {
    // 按横坐标排序
    return p1.right < p2.right;
}

double getDis(double x1, double y1, double x2, double y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

double getSqrt(Point p, double dd) {
    return sqrt(dd - p.y * p.y);
}

int main() {
    int n, d, t = 0;
    while (cin >> n >> d) {
        if (n == 0 && d == 0) {
            return 0;
        }
        double dd = d * d;
        // 当前最右侧雷达横坐标
        double xNow = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> points[i].x >> points[i].y;
            if (abs(points[i].y) > d) {
                ans = -1;
            }
            double tmp = getSqrt(points[i], dd);
            points[i].left = points[i].x - tmp;
            points[i].right = points[i].x + tmp;
        }
        if (ans == -1) {
            printf("Case %d: %d\n", ++t, ans);
            continue;
        }
        sort(points, points + n, cmp);
        for (int i = 0; i < n; ++i) {
            if (!ans || xNow < points[i].left) {
                xNow = points[i].right;
                ans++;
                continue;
            }
        }
        printf("Case %d: %d\n", ++t, ans);
    }
    return 0;
}