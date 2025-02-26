#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maxAbsoluteSum(vector<int>& a) {
        int n = a.size();
        int mn = 0;
        int mx = 0;
        int sum = 0;
        int ret = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            ret = max(ret, abs(sum - mn));
            ret = max(ret, abs(sum - mx));
            mn = min(mn, sum);
            mx = max(mx, sum);
        }
        return ret;
    }
};