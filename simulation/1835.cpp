// http://blog.sina.com.cn/s/blog_6f6e2aff01017rdv.html
#include <iostream>

using namespace std;

int arr[6][6];

int n, x, y, z, pos, head;

void init() {
    arr[0][1] = 2;
    arr[0][2] = 4;
    arr[0][4] = 5;
    arr[0][5] = 1;
    arr[1][2] = 0;
    arr[1][5] = 3;
    arr[1][0] = 5;
    arr[1][3] = 2;
    arr[2][0] = 1;
    arr[2][3] = 4;
    arr[2][1] = 3;
    arr[2][4] = 0;
    arr[3][1] = 5;
    arr[3][4] = 2;
    arr[3][2] = 1;
    arr[3][5] = 4;
    arr[4][0] = 2;
    arr[4][3] = 5;
    arr[4][2] = 3;
    arr[4][5] = 0;
    arr[5][4] = 3;
    arr[5][1] = 0;
    arr[5][0] = 4;
    arr[5][3] = 1;
}

void move(int step) {
    if (pos == 0) x += step;
    else if (pos == 1) y += step;
    else if (pos == 2) z += step;
    else if (pos == 3) x -= step;
    else if (pos == 4) y -= step;
    else if (pos == 5) z -= step;
}

int main() {
    init();
    int T;
    scanf("%d", &T);
    char dir[13];
    while (T--) {
        scanf("%d", &n);
        x = y = z = pos = 0;
        head = 2;
        int step;
        while (n--) {
            scanf("%s %d", dir, &step);
            if (dir[0] == 'b') {
                pos = (pos + 3) % 6;
            } else if (dir[0] == 'l') {
                pos = arr[pos][head];
            } else if (dir[0] == 'r') {
                pos = (arr[pos][head] + 3) % 6;
            } else if (dir[0] == 'u') {
                int t = pos;
                pos = head;
                head = (t + 3) % 6;
            } else if (dir[0] == 'd') {
                int t = pos;
                pos = (head + 3) % 6;
                head = t;
            }
            move(step);
        }
        printf("%d %d %d %d\n", x, y, z, pos);
    }
    return 0;
}

