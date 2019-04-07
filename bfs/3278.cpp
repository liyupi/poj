// http://poj.org/submit?problem_id=3278
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 100001;

int visited[MAXN] = {0};

int main() {
    int N, K;
    cin >> N >> K;
    int res = 0;
    queue<int> queue;
    queue.push(N);
    while (true) {
        bool flag = false;
        int size = queue.size();
        for (int i = 0; i < size; ++i) {
            int num = queue.front();
            if (num == K) {
                flag = true;
                break;
            }
            queue.pop();
            if (num + 1 <= 100000 && !visited[num + 1]) {
                queue.push(num + 1);
                visited[num + 1] = 1;
            }
            if (num - 1 >= 0 && !visited[num - 1]) {
                queue.push(num - 1);
                visited[num - 1] = 1;
            }
            if (num * 2 <= 100000 && !visited[num * 2]) {
                queue.push(num * 2);
                visited[num * 2] = 1;
            }
        }
        res++;
        if (flag) {
            break;
        }
    }
    cout << --res << endl;
    return 0;
}
