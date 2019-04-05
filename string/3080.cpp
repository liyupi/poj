// https://blog.csdn.net/qq_40932661/article/details/84970944
// 优化空间dp求LCS失败，没有考虑到按序匹配最长得不到最优解
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string str[11];

vector<string> res;

int main() {
    int t;
    cin >> t;
    while (t--) {
        res.clear();
        int num;
        cin >> num;
        for (int i = 0; i < num; ++i) {
            cin >> str[i];
        }
        int maxLen = 0;
        // 只能依次遍历所有长度的字串
        for (int i = 3; i <= 60; ++i) {
            int max = 60 - i;
            for (int j = 0; j <= max; ++j) {
                string subStr = str[0].substr(j, i);
                bool flag = true;
                for (int k = 1; k < num; ++k) {
                    if (str[k].find(subStr) == string::npos) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    if (i > maxLen) {
                        res.clear();
                        maxLen = i;
                    }
                    res.push_back(subStr);
                }
            }
        }
        sort(res.begin(), res.end());
        if (res.empty()) {
            cout << "no significant commonalities" << endl;
        } else {
            cout << res[0] << endl;
        }

    }
}
