// http://poj.org/problem?id=3096
#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> myset;

int main() {
    string str;
    while (cin >> str && str[0] != '*') {
        int len = str.length() - 2;
        bool flag = true;
        for (int i = 1; i <= len; ++i) {
            myset.clear();
            int maxPos = str.length() - i;
            for (int j = 0; j < maxPos; ++j) {
                char pair[3] = {str[j], str[j + i], '\0'};
                if (myset.find(pair) != myset.end()) {
                    flag = false;
                    break;
                } else {
                    myset.insert(pair);
                }
            }
            if (!flag) {
                break;
            }
        }
        cout << str << " is " << (flag ? "" : "NOT ") << "surprising." << endl;
    }
}