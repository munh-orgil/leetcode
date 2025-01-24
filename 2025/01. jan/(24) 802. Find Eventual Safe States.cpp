#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& a) {
        int n = a.size();
        vector<int> cnt(n, 0), vis(n, 0);
        vector<vector<int>> b(n);
        for (int i = 0; i < n; i++) {
            cnt[i] = a[i].size();
            for (int j = 0; j < a[i].size(); j++) {
                b[a[i][j]].push_back(i);
            }
        }
        queue<int> q;
        do {
            while (q.size()) {
                int x = q.front();
                q.pop();
                for (int i = 0; i < b[x].size(); i++) {
                    cnt[b[x][i]]--;
                }
            }
            for (int i = 0; i < n; i++) {
                if (!cnt[i] && !vis[i]) {
                    q.push(i);
                    vis[i] = 1;
                }
            }
        } while (q.size());

        vector<int> ret;
        for (int i = 0; i < n; i++) {
            if (vis[i]) ret.push_back(i);
        }
        return ret;
    }
};