#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minimumRecolors(string s, int k) {
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            cnt += (s[i] == 'B');
        }
        int ret = k - cnt;
        for (int i = k; i < n; i++) {
            cnt += (s[i] == 'B');
            cnt -= (s[i - k] == 'B');
            ret = min(ret, k - cnt);
        }
        return ret;
    }
};