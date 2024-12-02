#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int isPrefixOfWord(string s, string t) {
        int n = s.size();
        int m = t.size();
        int ret = 1;
        for (int i = 0; i <= n - m; i++) {
            bool ok = 1;
            for (int j = 0; j < m; j++) {
                if (s[i + j] != t[j]) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                return ret;
            }
            while (i < n && s[i] != ' ') {
                i++;
            }
            ret++;
        }
        return -1;
    }
};