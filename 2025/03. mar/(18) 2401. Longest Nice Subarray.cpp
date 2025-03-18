#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int longestNiceSubarray(vector<int>& a) {
        int n = a.size();
        vector<int> last(30, -1);
        int mx = -1, ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 30; j++) {
                if (a[i] & (1 << j)) {
                    mx = max(mx, last[j]);
                    last[j] = i;
                }
            }
            ret = max(ret, i - mx);
        }
        return ret;
    }
};