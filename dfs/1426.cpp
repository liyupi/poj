// https://blog.csdn.net/qq_42964711/article/details/81938661
// bfs超时，dfs能过，不要求求解最短路时就用dfs吧
#include <iostream>
#include <queue>

using namespace std;

int n;
bool flag = false;

void dfs(long long num, int step) {
    if (step > 18 || flag) {
        return;
    }
    if (!(num % n)) {
        printf("%lld\n", num);
        flag = true;
        return;
    }
    dfs(num * 10 + 1, step + 1);
    dfs(num * 10, step + 1);
}

/*long long bfs() {
    queue<long long> queue;
    queue.push(1);
    while (!queue.empty()) {
        long long tmp = queue.front();
        queue.pop();
        for (int i = 0; i < 2; ++i) {
            long long next = tmp * 10 + i;
            if (!(next % n)) {
                return next;
            }
            queue.push(next);
        }
    }
    return -1;
}*/

int main() {
    while (cin >> n) {
        if (!n) {
            break;
        }
//        printf("%lld\n", bfs());
        flag = false;
        dfs(1, 0);
    }
    return 0;
}
