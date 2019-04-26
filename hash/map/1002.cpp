// http://poj.org/problem?id=1002
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<int, int> mmap;

int dial[27] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 0, 7, 7, 8, 8, 8, 9, 9, 9, 0};

int main() {
    int N;
    while (cin >> N) {
        mmap.clear();
        string str;
        for (int i = 0; i < N; ++i) {
            cin >> str;
            int sum = 0;
            int len = str.length();
            for (int j = 0; j < len; j++) {
                if (isalpha(str[j])) {
                    str[j] = 48 + dial[str[j] - 65];
                }
                if (isdigit(str[j])) {
                    sum *= 10;
                    sum += str[j] - 48;
                }
            }
            if (mmap[sum]) {
                mmap[sum]++;
            } else {
                mmap[sum] = 1;
            }
        }
        bool flag = false;
        map<int, int>::iterator iter = mmap.begin();
        while (iter != mmap.end()) {
            if (iter->second > 1) {
                int num = iter->first;
                flag = true;
                printf("%03d-%04d %d\n", num / 10000, num % 10000, iter->second);
            }
            iter++;
        }
        if (!flag) {
            printf("No duplicates.\n");
        }
    }
}