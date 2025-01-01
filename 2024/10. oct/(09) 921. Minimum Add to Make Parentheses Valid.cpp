#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minAddToMakeValid(string s) {
        int n = s.size();
        int cnt = 0;
        int ret = 0;
        for (int i = 0; i < n; i++) {
            cnt += (s[i] == '(' ? 1 : -1);
            if (cnt < 0) {
                ret++;
                cnt = 0;
            }
        }
        ret += cnt;
        return ret;
    }
};
