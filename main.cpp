// https://blog.csdn.net/liu940204/article/details/51254821
// 设计hash，注意hash的设计不能太集中
#include <iostream>

using namespace std;

int N, K;

const int MAXN = 100001;
const int MAXK = 31;
const int BIG_PRIME = 1000007;

int sums[MAXN][MAXK] = {0};
int nums[MAXN][MAXK] = {0};

int hashTable[BIG_PRIME][10];

int getHash(int i) {
    int sum = 0;
    for (int j = 1; j < K; ++j) {
        sum += nums[i][j] * j % BIG_PRIME;
    }
    return sum % BIG_PRIME;
}

bool same(int a, int b) {
    for (int i = 1; i < K; ++i) {
        if (nums[a][i] != nums[b][i]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> N >> K;
    int res = 0;
    memset(hashTable, -1, sizeof(hashTable));
    for (int i = 1; i <= N; ++i) {
        int num;
        scanf("%d", &num);
        for (int j = 0; j < K; ++j) {
            sums[i][j] = sums[i - 1][j] + (num & 1);
            nums[i][j] = sums[i][j] - sums[i][0];
            num >>= 1;
        }
        hashTable[0][0] = 0;
        int hash = getHash(i);
        int k = 0;
        while (hashTable[hash][k] != -1) {
            if (same(i, hashTable[hash][k])) {
                res = max(res, i - hashTable[hash][k]);
                break;
            }
            k++;
        }
        if (hashTable[hash][k] == -1) {
            hashTable[hash][k] = i;
        }
    }
    printf("%d\n", res);
    return 0;
}
