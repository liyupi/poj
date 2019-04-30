// http://poj.org/problem?id=1146
// 字典序
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 51;

char word[MAXN];

void reverse(int left, int right) {
    while (left < right) {
        swap(word[left], word[right]);
        left++;
        right--;
    }
}

void replaceMinBigger(int pos, int len) {
    int c = word[pos];
    int min = 130;
    int minPos = -1;
    for (int i = pos; i < len; ++i) {
        if (word[i] > c && word[i] < min) {
            min = word[i];
            minPos = i;
        }
    }
    swap(word[pos], word[minPos]);
}

int main() {
    while (scanf("%s", word) && word[0] != '#') {
        int len = strlen(word);
        int pos = -1;
        for (int i = len - 1; i > 0; --i) {
            if (word[i] > word[i - 1]) {
                pos = i - 1;
                break;
            }
        }
        if (pos == -1) {
            printf("No Successor\n");
            continue;
        }
        reverse(pos + 1, len - 1);
        replaceMinBigger(pos, len);
        printf("%s\n", word);
    }
}

