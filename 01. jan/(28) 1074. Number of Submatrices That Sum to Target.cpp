#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);

        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> prefix(n + 1, vector<int> (m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefix[i + 1][j + 1] = prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j] + matrix[i][j];
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 0; k < i; k++) {
                    for (int l = 0; l < j; l++) {
                        if (prefix[i][j] - prefix[i][l] - prefix[k][j] + prefix[k][l] == target) {
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};