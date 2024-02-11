#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()

class Solution {
public:
    vector<vector<vector<int>>> dp;
    vector<vector<int>> arr;
    int cherryPickup(vector<vector<int>>& grid) {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);

        int n = grid.size();
        int m = grid[0].size();
        arr = grid;
        dp.resize(n, vector<vector<int>> (m, vector<int> (m, -1)));
        return DFS(0, 0, m - 1);
    }

    int DFS(int row, int a, int b) {
        if (a < 0 || b < 0 || a >= arr[0].size() || b >= arr[0].size() || row == arr.size()) {
            return 0;
        }
        if (dp[row][a][b] != -1) {
            return dp[row][a][b];
        }
        int ret = arr[row][a] + arr[row][b];
        int mx = 0;
        for (int i = a - 1; i <= a + 1; i++) {
            for (int j = b - 1; j <= b + 1; j++) {
                if (i < j) {
                    mx = max(mx, DFS(row + 1, i, j));
                }
            }
        }
        ret += mx;
        return dp[row][a][b] = ret;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    Solution sol = Solution{};
    int res = sol.cherryPickup(a);
    cout << res << endl;
}