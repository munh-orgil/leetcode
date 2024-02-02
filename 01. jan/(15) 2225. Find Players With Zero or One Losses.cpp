#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()
#define ll long long

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = matches.size();
        unordered_map<int, int> losses;
        for (int i = 0; i < n; i++) {
            losses[matches[i][1]]++;
            losses[matches[i][0]] += 0;
        }
        vector<vector<int>> ans(2);
        for (auto [key, val] : losses) {
            if (val < 2) {
                ans[val].push_back(key);
            }
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};

int main() {
    Solution sol = Solution{};
    int n;
    cin >> n;
    vector<vector<int>> matches(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        matches[i] = { u, v };
    }
    auto res = sol.findWinners(matches);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}