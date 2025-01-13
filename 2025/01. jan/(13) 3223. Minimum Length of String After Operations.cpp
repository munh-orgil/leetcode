#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minimumLength(string& s) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
        }
        int ret = 0;
        for (int i = 0; i < 26; i++) {
            if (!cnt[i]) continue;
            ret += 2 - cnt[i] % 2;
        }
        return ret;
    }
};