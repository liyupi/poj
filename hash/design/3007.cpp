// http://poj.org/submit?problem_id=3007
// stl的hashSet效率竟然跟不上，自己设计hash拉链，注意hash链的next要初始化
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int PRIME = 5987;

struct Node {
    string str;
    struct Node *next;
    Node() {
        next = 0;
    }
} *nodes[PRIME];

int res;

void addHash(const string &str) {
    int len = str.length();
    int sum = 0;
    for (int i = 0; i < len; ++i) {
        sum = (sum % PRIME + (str[i] - 97)) * i;
    }
    sum = abs(sum) % PRIME;
    Node *pos = nodes[sum];
    if (!pos) {
        Node *tmp = new Node;
        tmp->str = str;
        nodes[sum] = tmp;
    } else {
        if (pos->str == str) {
            return;
        }
        while (pos->next) {
            pos = pos->next;
            if (pos->str == str) {
                return;
            }
        }
        Node *tmp = new Node;
        tmp->str = str;
        pos->next = tmp;
    }
    res++;
}

int main() {
    int N;
    while (cin >> N) {
        string str;
        for (int i = 0; i < N; ++i) {
            cin >> str;
            // 指针地址变为0，即NULL
            memset(nodes, 0, sizeof(nodes));
            res = 0;
            int len = str.length();
            for (int i = 1; i < len; ++i) {
                string part1 = str.substr(0, i);
                string part2 = str.substr(i, len - i);
                string rpart1, rpart2;
                rpart1.assign(part1.rbegin(), part1.rend());
                rpart2.assign(part2.rbegin(), part2.rend());
                addHash(part1 + part2);
                addHash(part2 + part1);
                addHash(rpart1 + part2);
                addHash(part2 + rpart1);
                addHash(part1 + rpart2);
                addHash(rpart2 + part1);
                addHash(rpart1 + rpart2);
                addHash(rpart2 + rpart1);
            }
            cout << res << endl;
        }
    }
}