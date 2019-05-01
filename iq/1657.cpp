// http://poj.org/problem?id=1657
#include <iostream>
#include <cmath>

using namespace std;

char start[3];
char final[3];

int getWang() {
    int x = abs(final[0] - start[0]);
    int y = abs(final[1] - start[1]);
    return x + y - min(x, y);
}

int getHou() {
    if (start[0] == final[0] && start[1] == final[1]) {
        return 0;
    }
    if (start[0] == final[0] || start[1] == final[1] || abs(final[0] - start[0]) == abs(final[1] - start[1])) {
        return 1;
    }
    return 2;
}

int getChe() {
    int num = 2;
    if (start[0] == final[0]) {
        num--;
    }
    if (start[1] == final[1]) {
        num--;
    }
    return num;
}

int getXiang() {
    if (start[0] == final[0] && start[1] == final[1]) {
        return 0;
    }
    if (abs(final[0] - start[0]) == abs(final[1] - start[1])) {
        return 1;
    }
    if ((start[0] + final[0]) % 2 == (start[1] + final[1]) % 2) {
        return 2;
    }
    return -1;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        scanf("%s%s", start, final);
        printf("%d %d %d ", getWang(), getHou(), getChe());
        int num = getXiang();
        if (num == -1) {
            printf("Inf\n");
        } else {
            printf("%d\n", num);
        }
    }
}

