#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    int numberOfArrays(vector<int>& a, int lower, int upper) {
        int n = a.size();
        long long mn = 0, mx = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            mn = min(mn, sum);
            mx = max(mx, sum);
        }
        int ret = max(0LL, upper - lower - mx + mn + 1);
        return ret;
    }
};