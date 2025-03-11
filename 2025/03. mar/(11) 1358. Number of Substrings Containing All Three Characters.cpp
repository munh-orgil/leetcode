#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int numberOfSubstrings(string s) {
        vector<int> cnt(3, 0);
        int n = s.size();
        int l = 0, ret = 0, x;
        for (int r = 0; r < n; r++) {
            cnt[s[r] - 'a']++;
            if (cnt[0] * cnt[1] * cnt[2] == 0) {
                continue;
            }
            x = 1;
            while (cnt[0] * cnt[1] * cnt[2] > 0) {
                cnt[s[l] - 'a']--;
                l++;
                x++;
            }
            ret += (n - r) * x;
        }
        return ret;
    }
};