// https://www.cnblogs.com/zzhzz/p/5837815.html
#include <iostream>

using namespace std;

int a[21] = {0};

int main() {
    int t;
    while(cin >> t) {
        while (t--) {
            int n;
            cin >> n;
            for (int i = 1; i <= n; ++i) {
                cin >> a[i];
                int j = i - 1;
                // 必须让左括号的个数和右括号匹配 i - j为右括号个数，a[i]-a[j]为左括号个数
                while (a[i] - a[j] < i - j) {
                    j--;
                }
                cout << i - j << " ";
            }
            cout << endl;
        }

    }
}