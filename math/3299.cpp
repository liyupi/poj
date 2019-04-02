// https://blog.csdn.net/lyy289065406/article/details/6642582
#include <iostream>
#include <cmath>

using namespace std;

const int INF = 999999;

double getH(double D) {
    return 0.5555 * (6.11 * exp(5417.7530 * ((1 / 273.16) - (1 / (D + 273.16)))) - 10.0);
}

int main() {
    char type;
    while (true) {
        double T = INF, D = INF, H = INF;
        for (int i = 0; i < 2; ++i) {
            cin >> type;
            if (type == 'E') {
                return 0;
            } else if (type == 'T') {
                cin >> T;
            } else if (type == 'D') {
                cin >> D;
            } else {
                cin >> H;
            }
        }
        if (T == INF) {
            T = H - getH(D);
        } else if (D == INF) {
            D = 1 / (-log(((H - T) / 0.5555 + 10.0) / 6.11) / 5417.7530 + 1 / 273.16) - 273.16;
        } else if (H == INF) {
            H = T + getH(D);
        }
        printf("T %.1lf D %.1lf H %.1lf\n", T, D, H);
    }
}