// http://poj.org/problem?id=1003
#include <iostream>

using namespace std;

int main() {
    double c;
    while(~scanf("%lf", &c) && c != 0) {
        int n = 1;
        double sum = 0;
        while(sum < c) {
            sum += 1.0 / ++n;
        }
        printf("%d card(s)\n", n - 1);
    }
    return 0;
}