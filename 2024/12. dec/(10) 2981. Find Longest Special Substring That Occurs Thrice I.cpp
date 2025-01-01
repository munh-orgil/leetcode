#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maximumLength(string s) {
        int n = s.size();
        vector<vector<int>> cnt(26);
        int cur = 1;
        char ch = s[0];
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                cnt[ch - 'a'].push_back(cur);
                cur = 1;
                ch = s[i];
                continue;
            }
            cur++;
        }
        cnt[ch - 'a'].push_back(cur);
        int ret = 0;
        for (vector<int>& a : cnt) {
            sort(a.rbegin(), a.rend());
            if (a.size() > 0) {
                ret = max(ret, a[0] - 2);
            }
            if (a.size() > 1) {
                ret = max(ret, min(a[0] - 1, a[1]));
            }
            if (a.size() > 2) {
                ret = max(ret, a[2]);
            }
        }
        return (ret == 0 ? -1 : ret);
    }
};