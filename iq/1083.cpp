// https://blog.csdn.net/lvshubao1314/article/details/44227905
#include <iostream>

using namespace std;

int room[402] = {0};

int main() {
    int t;
    cin >> t;
    while(t--) {
        for (int i = 1; i <= 400; ++i) {
            room[i] = 0;
        }
        int n;
        cin >> n;
        int from, to;
        for (int i = 1; i <= n; ++i) {
            cin >> from >> to;
            if (to < from) {
                swap(to, from);
            }
            if (!(from % 2)) {
                from--;
            }
            if (to % 2) {
                to++;
            }
            for (int j = from; j <= to; ++j) {
                room[j]++;
            }
        }
        int res = 0;
        for (int i = 1; i <= 400; ++i) {
            res = max(room[i], res);
        }
        cout << res * 10 << endl;
    }
}
