// http://poj.org/problem?id=1256
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 15;

char word[MAXN];

int main() {
    int t;
    cin >> t;
    while (t--) {
        scanf("%s", word);
        int len = strlen(word);
        sort(word, word + len);
        do {
            printf("%s\n", word);
        } while (next_permutation(word, word + len));
    }
}

