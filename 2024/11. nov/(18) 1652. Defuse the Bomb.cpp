#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> decrypt(const vector<int>& a, int k) {
        int n = a.size();
        vector<int> ret(n, 0);
        if (!k) return ret;
        int dir = k / abs(k);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= abs(k); j++) {
                ret[i] += a[(i + j * dir + n) % n];
            }
        }
        return ret;
    }
};