// https://blog.csdn.net/huatian5/article/details/51519912
#include <iostream>
#include <string>


using namespace std;

int map[4][4] = {0};

/**
 * 翻转
 * @param x
 * @param y
 */
void flip(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        map[i][y] = !map[i][y];
    }
    for (int j = 0; j < 4; ++j) {
        map[x][j] = !map[x][j];
    }
    // 被翻了两次，翻回来
    map[x][y] = !map[x][y];
}

int main() {
    string str;
    for (int i = 0; i < 4; ++i) {
        cin >> str;
        for (int j = 0; j < 4; ++j) {
            if (str[j] == '+') {
                flip(i, j);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (map[i][j]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (map[i][j]) {
                cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }

    return 0;
}