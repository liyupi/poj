// http://poj.org/problem?id=1016
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <map>

using namespace std;

const int MAXN = 200;

// 第几个数有几个
int nums[MAXN];

// 用来判断循环
map<string, int> mmap;

int main() {
    string str;
    while (cin >> str && str != "-1") {
        mmap.clear();
        cout << str;
        int i;
        for (i = 0; i < 15; ++i) {
            mmap[str] = i;
            int len = str.length();
            int maxNum = 0;
            for (int j = 0; j < len; ++j) {
                int num = str[j] - 48;
                maxNum = max(maxNum, num);
                nums[num]++;
            }
            stringstream ss;
            for (int j = 0; j <= maxNum; ++j) {
                if (nums[j] > 0) {
                    ss << nums[j] << j;
                }
            }
            memset(nums, 0, sizeof(nums));
            str = ss.str();
            if (mmap.find(str) != mmap.end()) {
                if (i == mmap[str]) {
                    if (i == 0) {
                        cout << " is self-inventorying" << endl;
                    } else {
                        cout << " is self-inventorying after " << i << " steps" << endl;
                    }
                } else {
                    cout << " enters an inventory loop of length " << i - mmap[str] + 1 << endl;
                }
                break;
            }
        }
        if (i == 15) {
            cout << " can not be classified after 15 iterations" << endl;
        }
    }
    return 0;
}