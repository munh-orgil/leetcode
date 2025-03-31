#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    long long putMarbles(vector<int>& w, int k) {
        int n = w.size();
        vector<int> a(n - 1);
        for (int i = 0; i < n - 1; i++) {
            a[i] = w[i] + w[i + 1];
        }
        sort(a.begin(), a.end());
        long long mn = 0, mx = 0;
        for (int i = 0; i < k - 1; i++) {
            mn += a[i];
        }
        for (int i = n - 2; i >= n - k; i--) {
            mx += a[i];
        }
        return mx - mn;
    }
};