#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        if (n == 1) return 0;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = { arrays[i][0], arrays[i].back() };
        }
        sort(a.begin(), a.end());
        int ret = a[0].second - a[1].first;
        for (int i = 1; i < n; i++) {
            ret = max(ret, a[i].second - a[0].first);
        }
        return ret;
    }
};