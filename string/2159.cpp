// https://cavenkaka.iteye.com/blog/1176257
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string cipher, plain;
    while (cin >> cipher >> plain) {
        long cLen = cipher.length();
        long pLen = plain.length();
        if (cLen != pLen) {
            cout << "NO" << endl;
            continue;
        }
        int cWords[26] = {0};
        int pWords[26] = {0};
        for (int i = 0;  i < cLen; ++i) {
            cWords[cipher[i] - 'A']++;
        }
        for (int i = 0; i < pLen; ++i) {
            pWords[plain[i] - 'A']++;
        }
        sort(cWords, cWords + 26);
        sort(pWords, pWords + 26);
        bool flag = true;
        for (int i = 0; i < 26; ++i) {
            if (cWords[i] != pWords[i]) {
                flag = false;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
}