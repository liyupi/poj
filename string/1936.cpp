// http://poj.org/problem?id=1936
#include <iostream>
#include <string>

using namespace std;

int main() {
    string str1, str2;
    while (cin >> str1 >> str2) {
        int len1 = str1.length();
        int len2 = str2.length();
        int i = 0, j = 0;
        while (i < len1 && j < len2) {
            if (str1[i] == str2[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        if (i == len1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
