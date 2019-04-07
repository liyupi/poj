// http://poj.org/problem?id=3094
#include <iostream>
#include <string>

using namespace std;


int main() {
    string str;
    while(getline(cin, str)) {
        if (str == "#") {
            break;
        }
        int len = str.length();
        long long sum = 0;
        int multi = 1;
        for (int i = 0; i < len; ++i) {
            if (str[i] != ' ') {
                sum += multi * (str[i] - 64);
            }
            multi++;
        }
        cout << sum << endl;
    }
    return 0;
}
