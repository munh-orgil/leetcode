#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<bool> isArraySpecial(vector<int>& a, vector<vector<int>>& queries) {
        int n = a.size();
        vector<int> b;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] % 2 == a[i + 1] % 2) {
                b.push_back(i);
            }
        }
        vector<bool> ret;
        for (vector<int>& q : queries) {
            int l = q[0];
            int r = q[1];
            vector<int>::iterator it = lower_bound(b.begin(), b.end(), l);
            if (it != b.end() && *it < r) {
                ret.push_back(false);
            } else {
                ret.push_back(true);
            }
        }
        return ret;
    }
};