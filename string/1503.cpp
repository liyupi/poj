// http://poj.org/problem?id=1503
#include <iostream>
#include <string>

using namespace std;

string getSum(string a, string b) {
    int lenA = a.length();
    int lenB = b.length();
    string sum;
    int i = lenA - 1;
    int j = lenB - 1;
    int carry = 0;
    while (i >= 0 || j >= 0) {
        char ac = i < 0 ? '0' : a[i--];
        char bc = j < 0 ? '0' : b[j--];
        int num = ac + bc - 48 + carry;
        if (num > 57) {
            carry = 1;
            num -= 10;
        } else {
            carry = 0;
        }
        sum = (char)num + sum;
    }
    return carry ? "1" + sum : sum;
}

int main() {
    string a = "0", b;
    while (cin >> b) {
        if (b == "0") {
            break;
        }
        a = getSum(a, b);
    }
    cout << a << endl;
    return 0;
}
