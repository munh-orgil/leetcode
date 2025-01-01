#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minChanges(string& s) {
        int n = s.size();
        int cnt = 1;
        int ret = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                ret += cnt;
            }
            cnt ^= 1;
        }
        ret += cnt;
        return ret;
    }
};