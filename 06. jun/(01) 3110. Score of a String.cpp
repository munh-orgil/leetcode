#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int scoreOfString(string s) {
        int n = s.size();
        int ret = 0;
        for (int i = 1; i < n; i++) {
            ret += abs(s[i] - s[i - 1]);
        }
        return ret;
    }
};