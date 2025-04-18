#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string s = countAndSay(n - 1);
        n = s.size();
        int cnt = 0;
        char ch = 0;
        string ret = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != ch) {
                if (ch > 0) {
                    ret += to_string(cnt);
                    ret += ch;
                }
                cnt = 0;
                ch = s[i];
            }
            cnt++;
        }
        ret += to_string(cnt);
        ret += ch;
        return ret;
    }
};