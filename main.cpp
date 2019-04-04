// http://poj.org/problem?id=2996
// 2993的cp题，字符串拼接
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int ROW = 17;
const int COL = 33;

char chess[ROW + 1][COL + 1];

stringstream wStrs[100];

stringstream bStrs[100];

void store(int i, int j, bool upper) {
    char c = chess[2 * i][4 * j - 1];
    if (c == ':' || c == '.') {
        return;
    }
    if (upper) {
        if (isupper(c)) {
            if (c != 'P') {
                wStrs[c] << c;
            }
            wStrs[c] << (char) (j + 96) << (9 - i) << ",";
        }
    } else {
        if (!isupper(c)) {
            if (c != 'p') {
                bStrs[c - 32] << (char) (c - 32);
            }
            bStrs[c - 32] << (char) (j + 96) << (9 - i) << ",";
        }
    }
}

int main() {
    // input
    for (int i = 1; i <= ROW; ++i) {
        for (int j = 1; j <= COL; ++j) {
            cin >> chess[i][j];
        }
    }
    // deal
    // 白色反序
    for (int i = 8; i >= 1; i--) {
        for (int j = 1; j <= 8; ++j) {
            store(i, j, true);
        }
    }
    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            store(i, j, false);
        }
    }
    cout << "White: ";
    cout << wStrs['K'].str() << wStrs['Q'].str() << wStrs['R'].str() << wStrs['B'].str() << wStrs['N'].str() << wStrs['P'].str().substr(0, wStrs['P'].str().length() - 1);
    cout << endl;
    cout << "Black: ";
    cout << bStrs['K'].str() << bStrs['Q'].str() << bStrs['R'].str() << bStrs['B'].str() << bStrs['N'].str() << bStrs['P'].str().substr(0, wStrs['P'].str().length() - 1);
    cout << endl;
}