#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool judgeSquareSum(long long c) {
        long long rt, j;
        for (int i = 1; i * i <= c; i++) {
            j = c - i * i;
            rt = sqrt(j);
            if (rt * rt == j) {
                return true;
            }
        }
        return false;
    }
};