#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<vector<bool>> a(n, vector<bool>(n, 0));
        for (vector<int>& p : pre) {
            a[p[0]][p[1]] = 1;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j || i == k || j == k) continue;
                    a[i][j] = a[i][j] | (a[i][k] & a[k][j]);
                }
            }
        }
        vector<bool> ret;
        for (vector<int>& q : queries) {
            ret.push_back(a[q[0]][q[1]]);
        }
        return ret;
    }
};