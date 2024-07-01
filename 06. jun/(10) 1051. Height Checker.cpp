#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    int heightChecker(vector<int>& heights) {
        auto expected = heights;
        sort(expected.begin(), expected.end());
        int ret = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (expected[i] != heights[i]) {
                ret++;
            }
        }
        return ret;
    }
};