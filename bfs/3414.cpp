// https://blog.csdn.net/u012860063/article/details/37768979
// 注意，结构体地址
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct cup {
    int x, y;
    int step;
    int op; // 标记操作
    cup *pre; // 记录路径
};

queue<cup> Q;
stack<int> R;
int a, b, e;
int vis[101][101] = {0};
int ans;

void BFS(int x, int y) {
    cup c;
    cup t[400];
    c.x = 0, c.y = 0;
    c.op = 0;
    c.pre = NULL;
    c.step = 0;
    Q.push(c);
    vis[x][y] = 1;
    int count = -1;
    while (!Q.empty()) {
        count++;
        // 必须用数组，且结构体必须定义，否则该结构体变量的地址始终是队列首部地址，导致pre指针指向错误
        t[count] = Q.front();
        Q.pop();
        for (int i = 1; i <= 6; i++) {
            switch (i) {
                case 1:                        //fill a
                    c.x = a;
                    c.y = t[count].y;
                    c.op = 1;
                    break;
                case 2:                        //fill b
                    c.x = t[count].x;
                    c.y = b;
                    c.op = 2;
                    break;
                case 3:                        //drop a
                    c.x = 0;
                    c.y = t[count].y;
                    c.op = 3;
                    break;
                case 4:                        //drop b
                    c.x = t[count].x;
                    c.y = 0;
                    c.op = 4;
                    break;
                case 5:                        //pour a to b
                    if (t[count].x > b - t[count].y) {
                        c.x = t[count].x - (b - t[count].y);
                        c.y = b;
                    } else {
                        c.x = 0;
                        c.y = t[count].y + t[count].x;
                    }
                    c.op = 5;
                    break;
                case 6:                        //pour b to a
                    if (t[count].y > a - t[count].x) {
                        c.y = t[count].y - (a - t[count].x);
                        c.x = a;
                    } else {
                        c.x = t[count].x + t[count].y;
                        c.y = 0;
                    }
                    c.op = 6;
                    break;
            }
            if (vis[c.x][c.y])
                continue;
            vis[c.x][c.y] = 1;
            c.step = t[count].step + 1;
            c.pre = &t[count];
            if (c.x == e || c.y == e) {
                ans = c.step;
                while (c.pre) {
                    R.push(c.op);
                    c = *c.pre;
                }
                return;
            }
            Q.push(c);
        }
    }
}

void print() {
    while (!R.empty()) {
        int i = R.top();
        R.pop();
        switch (i) {
            case 1:
                cout << "FILL(1)" << endl;
                break;
            case 2:
                cout << "FILL(2)" << endl;
                break;
            case 3:
                cout << "DROP(1)" << endl;
                break;
            case 4:
                cout << "DROP(2)" << endl;
                break;
            case 5:
                cout << "POUR(1,2)" << endl;
                break;
            case 6:
                cout << "POUR(2,1)" << endl;
                break;
        }
    }
}

int main() {
    cin >> a >> b >> e;
    BFS(0, 0);
    if (ans == 0)
        cout << "impossible" << endl;
    else {
        cout << ans << endl;
        print();
    }
    return 0;
}