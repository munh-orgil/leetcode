#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minCost(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        dp[0][0] = 0;
        vector<int> moveX = { 0, 0, 1, -1 };
        vector<int> moveY = { 1, -1, 0, 0 };
        priority_queue < vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({ 0, 0, 0 });
        while (pq.size()) {
            auto vec = pq.top();
            pq.pop();
            for (int i = 0; i < 4; i++) {
                int u = vec[1] + moveX[i];
                int v = vec[2] + moveY[i];
                if (u < 0 || u >= n || v < 0 || v >= m) {
                    continue;
                }
                int dist = vec[0] + (i != a[vec[1]][vec[2]] - 1);
                if (dp[u][v] > dist) {
                    dp[u][v] = dist;
                    pq.push({ dist, u, v });
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};