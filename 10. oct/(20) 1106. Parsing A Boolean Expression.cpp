#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<bool> rec(const string& s, int l, int r) {
        int n = s.size();
        vector<bool> ret;
        for (int i = l; i < r; i++) {
            if (s[i] == 'f') {
                ret.push_back(0);
                continue;
            }
            if (s[i] == 't') {
                ret.push_back(1);
                continue;
            }
            if (s[i] != '|' && s[i] != '&' && s[i] != '!') {
                continue;
            }
            int cnt = 0;
            vector<bool> sub;
            for (int j = i + 1; j < r; j++) {
                if (s[j] == '(') {
                    cnt++;
                } else if (s[j] == ')') {
                    cnt--;
                }
                if (!cnt) {
                    sub = rec(s, i + 2, j - 1);
                    i = j;
                    break;
                }
            }
            bool val = sub[0];
            switch (s[i]) {
            case '&':
                for (int j = 1; j < sub.size(); j++) {
                    val &= sub[j];
                }
                break;
            case '|':
                for (int j = 1; j < sub.size(); j++) {
                    val |= sub[j];
                }
                break;
            case '!':
                val = !val;
                break;
            }
            ret.push_back(val);
        }
        return ret;
    }
    bool parseBoolExpr(string expression) {
        int n = expression.size();
        return rec(expression, 0, n)[0];
    }
};