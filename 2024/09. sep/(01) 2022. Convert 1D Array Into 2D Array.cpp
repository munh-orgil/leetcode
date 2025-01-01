#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector ret(m, vector<int> (n));

        if (int(original.size()) != m * n) {
            return vector<vector<int>>();
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ret[i][j] = original[i * n + j];
            }
        }

        return ret;
    }
};