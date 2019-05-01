// http://poj.org/problem?id=1517
#include <iostream>

using namespace std;

int main() {
    printf("n e\n");
    printf("- -----------\n");
    printf("0 1\n");
    printf("1 2\n");
    printf("2 2.5\n");
    int n = 2;
    double sum = 2.5;
    for (int i = 3; i <= 9; ++i) {
        n *= i;
        sum += 1.0 / n;
        printf("%d %.9lf\n", i, sum);
    }
}

