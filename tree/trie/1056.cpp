// http://poj.org/problem?id=1056
#include <iostream>
#include <string>

using namespace std;

struct Node {
    struct Node *children[2];
    bool word;
    Node() {
        for (int i = 0; i < 2; ++i) {
            children[i] = NULL;
        }
        word = false;
    }
} *root;

bool put(const string &str) {
    int len = str.length();
    Node *pos = root;
    bool flag = true;
    for (int i = 0; i < len; ++i) {
        int c = str[i] - 48;
        if (!pos->children[c]) {
            pos->children[c] = new Node;
        }
        pos = pos->children[c];
        if (pos->word) {
            flag = false;
        }
    }
    pos->word = true;
    return flag;
}

int main() {
    string str;
    int count = 0;
    while (cin >> str) {
        bool flag = true;
        root = new Node;
        bool first = true;
        while (first || cin >> str) {
            first = false;
            if (str == "9") {
                printf("Set %d is%s immediately decodable\n", ++count, flag ? "" : " not");
                break;
            }
            if (!put(str)) {
                flag = false;
            }
        }
    }
}

