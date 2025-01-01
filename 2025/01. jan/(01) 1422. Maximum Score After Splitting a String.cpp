#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maxScore(string s) {
        int n = s.size();
        int cnt0 = 0, cnt1 = 0;
        for (int i = 1; i < n; i++) {
            cnt1 += (s[i] == '1');
        }
        cnt0 = (s[0] == '0');
        int ret = 0;
        for (int i = 1; i < n; i++) {
            ret = max(ret, cnt0 + cnt1);
            cnt0 += (s[i] == '0');
            cnt1 -= (s[i] == '1');
        }
        return ret;
    }
};