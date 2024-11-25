#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<string, int> dp;
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    string convert(vector<vector<int>>& a) {
        string ret = "";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                ret += to_string(a[i][j]);
            }
        }
        return ret;
    }
    int slidingPuzzle(vector<vector<int>>& a) {
        string str = convert(a);
        int n = 2;
        int m = 3;
        dp["123450"] = 0;
        queue<vector<vector<int>>> q;
        q.push({ {1,2,3}, {4,5,0} });
        int dir[5] = { 1, 0, -1, 0, 1 };
        while (q.size()) {
            auto v = q.front();
            q.pop();
            string s = convert(v);
            if (s == str) {
                return dp[s];
            }
            int dist = dp[s];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!v[i][j]) {
                        for (int k = 0; k < 4; k++) {
                            int x = i + dir[k];
                            int y = j + dir[k + 1];
                            if (x < 0 || y < 0 || x >= n || y >= m) continue;
                            auto u = v;
                            swap(u[i][j], u[x][y]);
                            string str = convert(u);
                            if (dp.find(str) == dp.end()) {
                                dp[str] = dist + 1;
                                q.push(u);
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};