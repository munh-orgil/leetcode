#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minDifference(vector<int>& a) {
        int n = a.size();
        if (n <= 4) {
            return 0;
        }
        sort(a.begin(), a.end());
        int ret = INT_MAX;
        for (int i = 0; i <= 3; i++) {
            ret = min(ret, a[n - 1 - i] - a[3 - i]);
        }
        return ret;
    }
};