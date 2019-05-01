// http://poj.org/problem?id=1298
#include <iostream>
#include <cstring>

using namespace std;

char map[26] = {'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U'};

void printPlain(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        printf("%c", isupper(str[i]) ? map[str[i] - 65] : str[i]);
    }
    printf("\n");
}

int main() {
    char str[105];
    while (gets(str) && strcmp(str, "ENDOFINPUT")) {
        gets(str);
        printPlain(str);
        gets(str);
    }
}

