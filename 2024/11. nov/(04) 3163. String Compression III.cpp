#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    string compressedString(string s) {
        int n = s.size();
        string ret = "";
        auto f = [&](const char& ch, const int& cnt) {
            if (cnt) {
                ret.push_back('0' + cnt);
                ret.push_back(ch);
            }
            };
        int cnt = 0;
        char ch;
        for (int i = 0; i < n; i++) {
            if (cnt < 9 && s[i] == ch) {
                cnt++;
            } else {
                f(ch, cnt);
                ch = s[i];
                cnt = 1;
            }
        }
        f(ch, cnt);
        return ret;
    }
};