// http://poj.org/problem?id=2513
// 输出把小写打成了大写我c
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 500001;

int color = 0;
int du[MAXN] = {0};
int parent[MAXN];

struct Node {
    int i;
    Node *children[26];

    Node() {
        i = 0;
        memset(children, 0, sizeof(children));
    }
} *root;

int putAndGet(const char *str) {
    int len = strlen(str);
    Node *pos = root;
    for (int i = 0; i < len; ++i) {
        int c = str[i] - 97;
        if (!pos->children[c]) {
            pos->children[c] = new Node;
        }
        pos = pos->children[c];
    }
    if (!pos->i) {
        pos->i = ++color;
    }
    return pos->i;
}

void init() {
    for (int i = 1; i < MAXN; ++i) {
        parent[i] = i;
    }
}

int find(int num) {
    if (parent[num] != num) {
        parent[num] = find(parent[num]);
    }
    return parent[num];
}

void unite(int a, int b) {
    int i = find(a);
    int j = find(b);
    parent[j] = i;
}

int main() {
    char str1[12], str2[12];
    root = new Node;
    init();
    while (~scanf("%s%s", str1, str2)) {
        int a = putAndGet(str1);
        int b = putAndGet(str2);
        du[a]++;
        du[b]++;
        unite(a, b);
    }
    int count = 0;
    bool flag = true;
    // 连通图所有节点根节点相同，此处随便找一个节点的根节点
    int ancestor = find(1);
    for (int i = 1; i <= color; ++i) {
        if (du[i] % 2 == 1) {
            count++;
            if (count > 2) {
                flag = false;
                break;
            }
        }
        if (find(i) != ancestor) {
            flag = false;
            break;
        }
    }
    if (count == 1) {
        flag = false;
    }
    if (flag) {
        printf("Possible\n");
    } else {
        printf("Impossible\n");
    }
    return 0;
}