#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    int maxScoreSightseeingPair(vector<int>& a) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            a[i] += i;
        }
        int ret = 0;
        int mx = a[0];
        for (int i = 1; i < n; i++) {
            ret = max(ret, mx + a[i] - 2 * i);
            mx = max(mx, a[i]);
        }
        return ret;
    }
};