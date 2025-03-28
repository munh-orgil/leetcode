#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> maxPoints(vector<vector<int>>& a, vector<int>& queries) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> mn(n, vector<int>(m, 1e9));
        mn[0][0] = a[0][0];
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({ a[0][0], 0, 0 });
        const vector<int> d = { 1, 0, -1, 0, 1 };
        int u, v, to;
        while (pq.size()) {
            auto vec = pq.top();
            pq.pop();
            int p = vec[0];
            int x = vec[1];
            int y = vec[2];
            for (int i = 0; i < 4; i++) {
                u = x + d[i];
                v = y + d[i + 1];
                if (u < 0 || v < 0 || u >= n || v >= m) {
                    continue;
                }
                to = max(p, a[u][v]);
                if (to < mn[u][v]) {
                    mn[u][v] = to;
                    pq.push({ to, u, v });
                }
            }
        }
        vector<int> arr(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i * m + j] = mn[i][j];
            }
        }
        sort(arr.begin(), arr.end());
        vector<int> ret;
        for (int q : queries) {
            ret.push_back(lower_bound(arr.begin(), arr.end(), q) - arr.begin());
        }
        return ret;
    }
};