// http://poj.org/problem?id=3126
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int notPrime[10000] = {0};

int visited[10000];
int num1, num2;

void init() {
    for (int i = 2; i < 10000; ++i) {
        if (!notPrime[i]) {
            int j = 2;
            int num = i * j;
            while (num < 10000) {
                notPrime[num] = 1;
                j++;
                num = i * j;
            }
        }
    }
}

int getNum(int num, int pos, int k) {
    if (pos == 0) {
        return num % 1000 + k * 1000;
    } else if (pos == 1) {
        return (num / 1000) * 1000 + num % 100 + k * 100;
    } else if (pos == 2) {
        return (num / 100) * 100 + num % 10 + k * 10;
    } else {
        return (num / 10) * 10 + k;
    }
}

int bfs() {
    if (num1 == num2) {
        return 0;
    }
    queue<int> queue;
    queue.push(num1);
    visited[num1] = 1;
    int res = 0;
    while (!queue.empty()) {
        res++;
        int size = queue.size();
        for (int i = 0; i < size; ++i) {
            int tmp = queue.front();
            queue.pop();
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k <= 9; ++k) {
                    if (j == 0 && k == 0) {
                        continue;
                    }
                    int num = getNum(tmp, j, k);
                    if (num == num2) {
                        return res;
                    }
                    if (!visited[num] && !notPrime[num]) {
                        queue.push(num);
                        visited[num] = 1;
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    init();
    int t;
    cin >> t;
    while (t--) {
        memset(visited, 0, sizeof(visited));
        cin >> num1 >> num2;
        int val = bfs();
        if (val >= 0) {
            cout << val << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }
    return 0;
}
