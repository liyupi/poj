// https://blog.csdn.net/freezhanacmore/article/details/9614587
// 棋子可能是任意多个
#include <iostream>
#include <string>

using namespace std;

const int ROW = 17;
const int COL = 33;

char chess[ROW + 1][COL + 1];

// 初始化棋盘
void init() {
    for (int i = 1; i <= ROW; ++i) {
        for (int j = 1; j <= COL; ++j) {
            if (i % 2) {
                if (j % 4 == 1) {
                    chess[i][j] = '+';
                } else {
                    chess[i][j] = '-';
                }
            } else {
                if (j % 4 == 1) {
                    chess[i][j] = '|';
                } else {
                    if (((j - 1) / 4) % 2) {
                        chess[i][j] = ((i / 2) % 2) ? ':' : '.';
                    } else {
                        chess[i][j] = ((i / 2) % 2) ? '.' : ':';
                    }
                }
            }
        }
    }
}

void putOne(string str, bool upper) {
    if (str.length() == 2) {
        chess[1 + ROW - 2 * (str[1] - 48)][4 * (str[0] - 96) - 1] = upper ? 'P' : 'p';
    } else {
        chess[1 + ROW - 2 * (str[2] - 48)][4 * (str[1] - 96) - 1] = upper ? str[0] : (char) (str[0] + 32);
    }
}

void putAll(string str, bool upper) {
    str += ',';
    int len = str.length();
    int start = -1;
    int strLen = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] == ',') {
            putOne(str.substr(start, strLen), upper);
            start = -1;
        } else {
            if (start == -1) {
                start = i;
                strLen = 1;
            } else {
                strLen++;
            }
        }
    }
}


int main() {
    init();
    string str;
    cin >> str >> str;
    putAll(str, true);
    cin >> str >> str;
    putAll(str, false);
    for (int i = 1; i <= ROW; ++i) {
        for (int j = 1; j <= COL; ++j) {
            cout << chess[i][j];
        }
        cout << endl;
    }
}