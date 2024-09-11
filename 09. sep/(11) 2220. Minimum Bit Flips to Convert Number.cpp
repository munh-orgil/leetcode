#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minBitFlips(int start, int goal) {
        int ret = 0;
        while (start || goal) {
            if (start % 2 != goal % 2) {
                ret++;
            }
            start /= 2;
            goal /= 2;
        }
        return ret;
    }
};