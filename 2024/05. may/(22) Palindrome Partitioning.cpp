#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    bool isPalindrome(const string& s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - 1 - i]) {
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> dfs(const string& s) {
        int n = s.size();
        if (n == 0) {
            return { {} };
        }
        if (n == 1) {
            return { {s} };
        }
        string t, r;
        vector<vector<string>> subs, ret;
        vector<string> tmp;
        for (int i = 0; i < n; i++) {
            if (s[i] == s[0]) {
                t = "";
                r = "";
                for (int j = 0; j <= i; j++) {
                    t += s[j];
                }
                for (int j = i + 1; j < n; j++) {
                    r += s[j];
                }
                if (isPalindrome(t)) {
                    subs = dfs(r);
                    for (int j = 0; j < subs.size(); j++) {
                        tmp = { t };
                        for (int k = 0; k < subs[j].size(); k++) {
                            tmp.push_back(subs[j][k]);
                        }
                        ret.push_back(tmp);
                    }
                }
            }
        }
        return ret;
    }
    vector<vector<string>> partition(const string& s) {
        return dfs(s);
    }
};