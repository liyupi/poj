// http://poj.org/problem?id=3253
#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    priority_queue<int, vector<int>, greater<int>> queue;
    while (cin >> n) {
        int num;
        for (int i = 0; i < n; ++i) {
            cin >> num;
            queue.push(num);
        }
        long long sum = 0;
        while (queue.size() >= 2) {
            int a = queue.top();
            queue.pop();
            int b = queue.top();
            queue.pop();
            int tmp = a + b;
            queue.push(tmp);
            sum += tmp;
        }
        cout << sum << endl;
    }
}
