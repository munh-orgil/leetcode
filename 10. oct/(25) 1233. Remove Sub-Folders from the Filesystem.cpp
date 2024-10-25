#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end(), [&](string& x, string& y) {
            return x.size() < y.size();
            });
        map<string, bool> mp;
        string t;
        int n;
        bool ok;
        for (string s : folder) {
            t = "";
            n = s.size();
            ok = 1;
            for (int i = 0; i < n; i++) {
                if (s[i] == '/' && t != "") {
                    if (mp.find(t) != mp.end()) {
                        ok = 0;
                        break;
                    }
                }
                t += s[i];
            }
            if (ok) {
                mp[s] = 1;
            }
        }
        vector<string> ret;
        for (auto [s, _] : mp) {
            ret.push_back(s);
        }
        return ret;
    }
};