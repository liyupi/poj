// http://poj.org/problem?id=1005
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    while (cin >> N) {
        for (int i = 1; i <= N; ++i) {
            double x, y;
            scanf("%lf%lf", &x, &y);
            double dis = x * x + y * y;
            int Z = 0;
            double area = 0;
            double r = 0;
            while (r < dis) {
                Z++;
                area += 50;
                r = area * 2 / 3.1415926;
            }
            printf("Property %d: This property will begin eroding in year %d.\n", i, Z);
        }
        printf("END OF OUTPUT.\n");
    }
}