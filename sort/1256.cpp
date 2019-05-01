// http://poj.org/problem?id=1256
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 15;

char word[MAXN];

bool cmp(const char &a, const char &b) {
    if ((a >= 97 && b >= 97) || (a < 97 && b < 97)) {
        return a < b;
    } else if (a >= 97) {
        return a - 32 < b;
    } else if (b >= 97) {
        return a <= b - 32;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        scanf("%s", word);
        int len = strlen(word);
        sort(word, word + len, cmp);
        do {
            printf("%s\n", word);
        } while (next_permutation(word, word + len, cmp));
    }
}

