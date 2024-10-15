#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    long long minimumSteps(string s) {
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += (s[i] == '1');
        }
        long long ret = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ret += (n - cnt - i);
                cnt--;
            }
        }
        return ret;
    }
};
