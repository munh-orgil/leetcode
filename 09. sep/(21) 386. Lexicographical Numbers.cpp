#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    void dfs(int cur, int n, vector<int>& res) {
        if (cur > n) {
            return;
        }
        res.push_back(cur);
        for (int i = 0; i < 10; i++) {
            dfs(cur * 10 + i, n, res);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ret;
        for (int i = 1; i < 10; i++) {
            dfs(i, n, ret);
        }
        return ret;
    }
};