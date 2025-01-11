#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool canConstruct(string s, int k) {
        if (s.size() < k) return false;
        vector<int> cnt(26, 0);
        for (char ch : s) {
            cnt[ch - 'a'] ^= 1;
        }
        return accumulate(cnt.begin(), cnt.end(), 0) <= k;
    }
};