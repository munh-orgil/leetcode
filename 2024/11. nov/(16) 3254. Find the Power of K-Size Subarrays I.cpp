#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> resultsArray(vector<int>& a, int k) {
        int n = a.size();
        vector<int> idx(n + 1, 0);
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i - 1] + 1) {
                idx[i] = 1;
            }
        }
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            if (idx[i]) {
                cnt++;
            }
        }
        vector<int> ret(n - k + 1, -1);
        for (int i = 0; i <= n - k; i++) {
            if (idx[i]) {
                cnt--;
            }
            if (!cnt) {
                ret[i] = a[i] + k - 1;
            }
            if (idx[i + k]) {
                cnt++;
            }
        }
        return ret;
    }
};