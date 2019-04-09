// http://poj.org/problem?id=1416
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int cuts[6] = {0, 1, 0, 1, 1, 0};

vector<int> res;

int path[6];

int maxNum = -1;

// 个、十...
int nums[6];

int t, num;

int cutN;

int getSum() {
    int sum = 0;
    int tmp = 0;
    for (int i = 0; i < cutN; ++i) {
        tmp *= 10;
        tmp += nums[i];
        if (i == cutN - 1 || cuts[i]) {
            sum += tmp;
            tmp = 0;
        }
    }
    return sum;
}

// 依次遍历切点情况，最多32种
void dfs(int pos) {
    if (pos == cutN - 1) {
        int val = getSum();
        if (val <= t) {
            if (val == maxNum) {
                res.push_back(val);
            } else if (val > maxNum) {
                maxNum = val;
                res.clear();
                res.push_back(val);
                for (int i = 0; i < cutN; ++i) {
                    path[i] = cuts[i];
                }
            }
        }
        return;
    }
    for (int i = 0; i < 2; ++i) {
        cuts[pos] = i;
        dfs(pos + 1);
    }
}

void printPath() {
    cout << res[0];
    int tmp = 0;
    for (int i = 0; i < cutN; ++i) {
        tmp *= 10;
        tmp += nums[i];
        if (i == cutN - 1 || path[i]) {
            cout << " " << tmp;
            tmp = 0;
        }
    }
    cout << endl;
}

int main() {
    while (cin >> t >> num && (t || num)) {
        if (num == t) {
            cout << num << " " << num << endl;
            continue;
        }
        res.clear();
        maxNum = 0;
        cutN = 0;
        int tmp = num;
        // 求出数字位数
        while (tmp) {
            tmp /= 10;
            cutN++;
        }
        tmp = num;
        int i = cutN;
        while (tmp) {
            nums[--i] = tmp % 10;
            tmp /= 10;
        }
        dfs(0);
        if (res.size() > 1) {
            cout << "rejected" << endl;
        } else if (res.empty()) {
            cout << "error" << endl;
        } else {
            printPath();
        }
    }
    return 0;
}