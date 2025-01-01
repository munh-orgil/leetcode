#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maxChunksToSorted(vector<int>& a) {
        int n = a.size();
        int ret = 0;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur = max(cur, a[i]);
            if (i == cur) {
                ret++;
            }
        }
        return ret;
    }
};