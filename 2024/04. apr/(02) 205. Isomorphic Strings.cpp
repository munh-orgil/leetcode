#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    bool isIsomorphic(string s, string t) {
        vector<char> mp(256, 0);
        for (int i = 0; i < s.size(); i++) {
            if (mp[s[i]]) {
                if (mp[s[i]] != t[i]) {
                    return false;
                }
            }
            else {
                mp[s[i]] = t[i];
            }
        }
        for (int i = 0; i < 256; i++) {
            mp[i] = 0;
        }
        for (int i = 0; i < t.size(); i++) {
            if (mp[t[i]]) {
                if (mp[t[i]] != s[i]) {
                    return false;
                }
            }
            else {
                mp[t[i]] = s[i];
            }
        }
        return true;
    }
};