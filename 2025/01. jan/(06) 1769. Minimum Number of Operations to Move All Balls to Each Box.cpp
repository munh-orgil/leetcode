#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> minOperations(string s) {
        int n = s.size();
        int r = 0, m = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                r += i;
                m++;
            }
        }
        int l = 0, cnt = 0;
        vector<int> ret(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                r -= i;
                l += i;
                cnt++;
            }
            ret[i] = i * cnt - l + r - (m - cnt) * i;
        }
        return ret;
    }
};