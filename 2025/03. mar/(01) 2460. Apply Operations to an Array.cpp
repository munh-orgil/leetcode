#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> applyOperations(vector<int>& a) {
        int n = a.size();
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == a[i + 1]) {
                a[i] = 2 * a[i];
                a[i + 1] = 0;
            }
        }
        vector<int> ret(n, 0);
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (a[i]) {
                ret[idx] = a[i];
                idx++;
            }
        }
        return ret;
    }
};