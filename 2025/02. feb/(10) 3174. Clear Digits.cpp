#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    string clearDigits(string& s) {
        string ret = "";
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                ret.pop_back();
            } else {
                ret += s[i];
            }
        }
        return ret;
    }
};