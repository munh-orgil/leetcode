#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    string smallestNumber(string p) {
        int n = p.size();
        vector<bool> used(10, 0);
        function<bool(string, int)> rec;
        string ret = "";
        rec = [&](string s, int idx) {
            if (idx == n) {
                ret = s;
                return true;
            }
            int x = s.back() - '0';
            int l, r;
            if (p[idx] == 'I') {
                l = x + 1;
                r = 10;
            } else {
                l = 1;
                r = x;
            }
            for (int i = l; i < r; i++) {
                if (used[i]) continue;
                used[i] = 1;
                if (rec(s + char('0' + i), idx + 1)) {
                    return true;
                }
                used[i] = 0;
            }
            return false;
            };

        for (int i = 1; i < 10; i++) {
            used[i] = 1;
            if (rec(string(1, char('0' + i)), 0)) {
                return ret;
            }
            used[i] = 0;
        }
        return ret;
    }
};