#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (n > m) return false;
        s2 += "a";
        vector<int> cnt1(26, 0), cnt2(26, 0);
        for (int i = 0; i < n; i++) {
            cnt1[s1[i] - 'a']++;
        }
        for (int i = 0; i <= m; i++) {
            if (i < n) {
                cnt2[s2[i] - 'a']++;
                continue;
            }
            bool ok = 1;
            for (int j = 0; j < 26; j++) {
                if (cnt1[j] != cnt2[j]) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                return true;
            }
            cnt2[s2[i - n] - 'a']--;
            cnt2[s2[i] - 'a']++;
        }
        return false;
    }
};