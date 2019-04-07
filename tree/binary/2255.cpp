// http://poj.org/problem?id=2255
#include <iostream>
#include <string>

using namespace std;

string preStr, inStr;

void build(int pLeft, int iLeft, int iRight) {
    for (int i = iLeft; i < iRight; ++i) {
        if (inStr[i] == preStr[pLeft]) {
            build(pLeft + 1, iLeft, i);
            build(pLeft + 1 + i - iLeft, i + 1, iRight);
            cout << preStr[pLeft];
            return;
        }
    }
}

int main() {
    while (cin >> preStr >> inStr) {
        build(0, 0, inStr.length());
        cout << endl;
    }
    return 0;
}
