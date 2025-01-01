#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> getFinalState(vector<int>& a, int k, int m) {
        int n = a.size();
        while (k--) {
            int idx = 0;
            int mn = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (a[i] < mn) {
                    idx = i;
                    mn = a[i];
                }
            }
            a[idx] *= m;
        }
        return a;
    }
};