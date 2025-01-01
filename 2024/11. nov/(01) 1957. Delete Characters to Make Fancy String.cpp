#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    string makeFancyString(const string& s) {
        string ret = "";
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (ret.size() >= 2 && ret[ret.size() - 1] == s[i] && ret[ret.size() - 2] == s[i]) {
                continue;
            }
            ret += s[i];
        }
        return ret;
    }
};