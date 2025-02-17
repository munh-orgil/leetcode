#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int cnt(string s) {
        if (s == "") return 0;
        vector<int> c(26, 0);
        for (char ch : s) {
            c[ch - 'A']++;
        }
        int ret = fact(s.size());
        for (int i = 0; i < 26; i++) {
            ret /= fact(c[i]);
        }
        return ret;
    }
    int fact(int x) {
        int ret = 1;
        for (int i = 1; i <= x; i++) {
            ret *= i;
        }
        return ret;
    }
    int numTilePossibilities(string s) {
        int n = s.size();
        int x = 1 << n;
        sort(s.begin(), s.end());
        unordered_map<string, bool> mp;
        string t;
        int ret = 0;
        for (int i = 1; i < x; i++) {
            t = "";
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    t += s[j];
                }
            }
            if (mp[t]) continue;
            ret += cnt(t);
            mp[t] = true;
        }
        return ret;
    }
};