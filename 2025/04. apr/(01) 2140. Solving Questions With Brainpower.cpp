#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        vector<long long> a(n + 1, 0), mx(n + 1, 0);
        int r;
        for (int i = n - 1; i >= 0; i--) {
            r = min(n, i + q[i][1] + 1);
            a[i] = max({ a[i], a[r], mx[r] });
            a[i] += q[i][0];
            mx[i] = max(mx[i + 1], a[i]);
        }
        return *max_element(a.begin(), a.end());
    }
};