#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& a) {
        int n = a.size();
        unordered_map<int, int> cnt;
        unordered_map<int, set<int>> nxt;
        for (int i = 0; i < n; i++) {
            cnt[a[i][0]]++;
            cnt[a[i][1]]--;
            nxt[a[i][0]].insert(a[i][1]);
        }
        int st = a[0][0];
        for (auto [k, v] : cnt) {
            if (v == 1) {
                st = k;
            }
        }
        vector<vector<int>> ret;
        stack<int> s;
        function<void(int)> dfs;
        dfs = [&](int cur) {
            while (nxt[cur].size()) {
                int to = *nxt[cur].begin();
                s.push(to);
                nxt[cur].erase(to);
                dfs(to);
            }
            if (s.size() > 1) {
                int x = s.top();
                s.pop();
                int y = s.top();
                ret.push_back({ y, x });
            }
            };
        s.push(st);
        dfs(st);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
