#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> getMaximumXor(vector<int>& a, int maximumBit) {
        int n = a.size();
        vector<int> ret(n);
        int x = (1 << maximumBit) - 1;
        int s = 0;
        for (int i = 0; i < n; i++) {
            s ^= a[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            ret[n - i - 1] = s ^ x;
            s ^= a[i];
        }
        return ret;
    }
};