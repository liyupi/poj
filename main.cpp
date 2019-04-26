#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <string>

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1001;

int a[MAXN];

vector<double> nums;
set<int> myset;
map<string, int> mmap;
queue<int> myq;
stact<int> mystack;

int main() {
    int N;
    while(~scanf("%d", &N)) {
        int tmp;
        for (int i = 0; i < N; ++i) {
            scanf("%d", &tmp);
            nums.push_back(tmp);
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < N; ++i) {
            printf("%d\n", nums[i]);
        }
    }
    return 0;
}
