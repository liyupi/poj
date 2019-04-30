// http://poj.org/problem?id=1218
// 找平方数
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int num;
        cin >> num;
        int i = 1;
        while (i * i <= num) {
            i++;
        }
        cout << i - 1 << endl;
    }
}

