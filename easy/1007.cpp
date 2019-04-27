// http://poj.org/problem?id=1007
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAXN = 101;

struct Node {
    string str;
    int re;
} nodes[MAXN];

int len, A;

int getRe(string str) {
    int num = 0;
    for (int i = 1; i < len; ++i) {
        for (int j = 0; j < i; ++j) {
            num += str[i] < str[j];
        }
    }
    return num;
}

bool compare(const Node &n1, const Node &n2) {
    return n1.re < n2.re;
}

int main() {
    while (cin >> len >> A) {
        for (int i = 0; i < A; ++i) {
            cin >> nodes[i].str;
            nodes[i].re = getRe(nodes[i].str);
        }
        sort(nodes, nodes + A, compare);
        for (int i = 0; i < A; ++i) {
            cout << nodes[i].str << endl;
        }
    }

}