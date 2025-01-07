#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<string> stringMatching(vector<string>& s) {
        int n = s.size();
        vector<string> ret;
        bool ok;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || s[i].size() > s[j].size()) continue;
                for (int k = 0; k <= s[j].size() - s[i].size(); k++) {
                    ok = 1;
                    for (int l = 0; l < s[i].size(); l++) {
                        if (s[i][l] != s[j][k + l]) {
                            ok = 0;
                            break;
                        }
                    }
                    if (ok) {
                        break;
                    }
                }
                if (ok) {
                    ret.push_back(s[i]);
                    break;
                }
            }
        }
        return ret;
    }
};