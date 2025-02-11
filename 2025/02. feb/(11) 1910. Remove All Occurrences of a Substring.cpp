#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    string removeOccurrences(string s, string t) {
        int n = s.size();
        int m = t.size();
        string ret = "";
        for (int i = 0; i < n; i++) {
            ret += s[i];
            if (ret.size() >= m) {
                bool ok = 1;
                int l = ret.size() - m;
                for (int j = l; j < ret.size(); j++) {
                    if (ret[j] != t[j - l]) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                    ret.erase(ret.end() - m, ret.end());
                }
            }
        }
        return ret;
    }
};