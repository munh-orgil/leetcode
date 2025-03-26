#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minOperations(vector<vector<int>>& a, int x) {
        int n = a.size();
        int m = a[0].size();
        vector<int> b;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] % x != a[0][0] % x) {
                    return -1;
                }
                b.push_back(a[i][j] / x);
            }
        }
        sort(b.begin(), b.end());
        int v = b[b.size() / 2];
        int ret = 0;
        for (int i : b) {
            ret += abs(v - i);
        }
        return ret;
    }
};