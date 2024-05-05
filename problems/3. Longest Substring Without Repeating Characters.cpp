#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int lengthOfLongestSubstring(string s) {
        vector<int> pos(128, -1);
        int n = s.size();
        int last = -1;
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (pos[s[i]] > last) {
                ret = max(ret, i - last - 1);
                last = pos[s[i]];
            }
            pos[s[i]] = i;
        }
        if (last == -1) {
            return n;
        }
        ret = max(ret, n - 1 - last);
        return ret;
    }
};