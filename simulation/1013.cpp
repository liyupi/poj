// http://poj.org/problem?id=1013
// 模拟，数量小的时候枚举即可
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int zhen[12];

string l[3], r[3], res[3];

bool checkLight(int i) {
    bool flag = true;
    for (int j = 0; j < 3; ++j) {
        if (res[j] == "up") {
            if (r[j].find((char) (i + 65)) == string::npos) {
                flag = false;
                break;
            }
        } else if (res[j] == "down") {
            if (l[j].find((char) (i + 65)) == string::npos) {
                flag = false;
                break;
            }
        }
    }
    if (flag) {
        printf("%c is the counterfeit coin and it is light.\n", i + 65);
    }
    return flag;
}

bool checkWeight(int i) {
    bool flag = true;
    for (int j = 0; j < 3; ++j) {
        if (res[j] == "up") {
            if (l[j].find((char) (i + 65)) == string::npos) {
                flag = false;
                break;
            }
        } else if (res[j] == "down") {
            if (r[j].find((char) (i + 65)) == string::npos) {
                flag = false;
                break;
            }
        }
    }
    if (flag) {
        printf("%c is the counterfeit coin and it is heavy.\n", i + 65);
    }
    return flag;
}

bool check(int i) {
    return checkLight(i) ? true : checkWeight(i);
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        memset(zhen, 0, sizeof(zhen));
        for (int i = 0; i < 3; ++i) {
            cin >> l[i] >> r[i] >> res[i];
            if (res[i] == "even") {
                int len = l[i].length();
                for (int j = 0; j < len; ++j) {
                    zhen[l[i][j] - 65] = 1;
                    zhen[r[i][j] - 65] = 1;
                }
            }
        }
        for (int i = 0; i < 12; ++i) {
            // 有可能轻或重
            if (!zhen[i] && check(i)) {
                break;
            }
        }
    }
    return 0;
}