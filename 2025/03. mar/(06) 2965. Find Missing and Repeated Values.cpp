#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& a) {
        int n = a.size();
        vector<bool> vis(n * n + 1, 0);
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[a[i][j]] == 1) {
                    ret.push_back(a[i][j]);
                }
                vis[a[i][j]] = 1;
            }
        }
        for (int i = 1; i <= n * n; i++) {
            if (!vis[i]) ret.push_back(i);
        }
        return ret;
    }
};