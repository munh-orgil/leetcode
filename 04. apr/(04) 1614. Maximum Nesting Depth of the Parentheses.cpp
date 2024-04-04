#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maxDepth(string s) {
        int ret = 0;
        int cnt = 0;
        for (char c : s) {
            if (c == '(') {
                cnt++;
            }
            else if (c == ')') {
                cnt--;
            }
            ret = max(ret, cnt);
        }
        return ret;
    }
};