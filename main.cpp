// https://blog.csdn.net/freezhanacmore/article/details/9614587
// 棋子可能是任意多个
#include <iostream>

using namespace std;

const int ROW = 17;
const int COL = 33;

char chess[ROW + 1][COL + 1];

string wStrs[100];

string bStrs[100];

void store(int i, int j) {
    char c = chess[2 * i][4 * j - 1];
    if (c == ':' || c == '.') {
        return;
    }
    if (isupper(c)) {
        if (c != 'P') {
            wStrs[c] += c;
        }
        wStrs[c] += (char) (j + 96) + to_string(9 - i) + ",";
    } else {
        if (c != 'p') {
            bStrs[c] += c;
        }
        bStrs[c - 32] += (char) (c - 32);
        bStrs[c - 32] += (char) (j + 96) + to_string(9 - i) + ",";
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
    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            store(i, j);
        }
    }
    cout << "White: ";
    cout << wStrs['K'] << wStrs['Q'] << wStrs['R'] << wStrs['B'] << wStrs['N'] << wStrs['P'];
    cout << endl;
    cout << "Black: ";
    cout << bStrs['K'] << bStrs['Q'] << bStrs['R'] << bStrs['B'] << bStrs['N'] << bStrs['P'];
    cout << endl;
}