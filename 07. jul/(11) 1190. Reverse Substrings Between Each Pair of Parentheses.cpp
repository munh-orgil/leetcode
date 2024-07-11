#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    string s;
    pair<string, int> dfs(int pos) {
        int n = s.size();
        string ret = "";
        for (int i = pos; i < n; i++) {
            if (s[i] == '(') {
                auto [tmp, index] = dfs(i + 1);
                reverse(tmp.begin(), tmp.end());
                ret += tmp;
                i = index;
                continue;
            }
            if (s[i] == ')') {
                return { ret, i };
            }
            ret += s[i];
        }
        return { ret, n };
    }
    string reverseParentheses(string in) {
        s = in;
        return dfs(0).first;
    }
};