// http://poj.org/problem?id=3087
// 更像是一道模拟题
#include <iostream>

using namespace std;

char a[101];
char b[101];
char ab[202];
char origin[202];
char dst[202];

int bfs(int len) {
    int res = 0;
    while (true) {
        res++;
        int i = 0;
        while (i < len) {
            ab[2 * i] = b[i];
            ab[2 * i + 1] = a[i];
            i++;
        }
        if (!strcmp(ab, dst)) {
            return res;
        }
        if (!strcmp(ab, origin)) {
            return -1;
        }
        strncpy(a, ab, len);
        strncpy(b, ab + len, len);
    }
}

int main() {
    int t;
    cin >> t;
    int count = 1;
    while (t--) {
        int len;
        cin >> len;
        scanf("%s", a);
        scanf("%s", b);
        scanf("%s", dst);
        sprintf(ab, "%s%s", a, b);
        strcpy(origin, ab);
        printf("%d %d\n", count++, bfs(len));
    }
    return 0;
}
