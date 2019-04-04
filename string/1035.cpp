// http://poj.org/problem?id=1035
// 想用集合偷懒，但是为了保证顺序输出，只能用列表
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> dic;

void doPrint(string str) {
    bool find = false;
    string words;
    for (int k = 0; k < dic.size(); ++k) {
        const string &item = dic[k];
        int iLen = item.length();
        int sLen = str.length();
        int tmp = iLen - sLen;
        if (tmp > 1 || tmp < -1) {
            continue;
        }
        int i = 0, j = 0, count = 0;
        while (i < iLen && j < sLen) {
            if (item[i++] != str[j++]) {
                if (++count > 1) {
                    break;
                }
                if (iLen < sLen) {
                    i--;
                } else if (iLen > sLen) {
                    j--;
                }
            }
        }
        if (count == 0 && iLen == sLen) {
            find = true;
            break;
        }
        if (count < 2) {
            words += " " + item;
        }
    }
    if (find) {
        cout << str << " is correct" << endl;
    } else {
        cout << str << ":" + words << endl;
    }
}

int main() {
    string str;
    while (cin >> str) {
        if (str == "#") {
            break;
        }
        dic.push_back(str);
    }
    while (cin >> str) {
        if (str == "#") {
            break;
        }
        doPrint(str);
    }
    return 0;
}