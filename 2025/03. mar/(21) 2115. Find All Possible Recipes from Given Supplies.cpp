#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> can(supplies.begin(), supplies.end());
        unordered_map<string, int> mp;
        int n = recipes.size();
        for (int i = 0; i < n; i++) {
            mp[recipes[i]] = i;
        }
        function<bool(int)> rec;
        vector<int> vis(n, 0);
        rec = [&](int i) {
            for (string ing : ingredients[i]) {
                if (can.count(ing)) {
                    continue;
                }
                if (mp.find(ing) == mp.end()) {
                    return false;
                }
                if (vis[mp[ing]]) {
                    return false;
                }
                vis[mp[ing]] = 1;
                if (!rec(mp[ing])) {
                    return false;
                }
                vis[mp[ing]] = 0;
            }
            can.insert(recipes[i]);
            return true;
            };
        vector<string> ret;
        for (int i = 0; i < n; i++) {
            vis[i] = 1;
            if (rec(i)) {
                ret.push_back(recipes[i]);
            }
            vis[i] = 0;
        }
        return ret;
    }
};