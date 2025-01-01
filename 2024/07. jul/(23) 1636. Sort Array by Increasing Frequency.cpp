#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            cnt[nums[i]]++;
        }
        vector<pair<int, int>> p;
        for (auto [k, v] : cnt) {
            p.push_back({ k, v });
        }
        sort(p.begin(), p.end(), [&](pair<int, int> x, pair<int, int> y) {
            if (x.second == y.second) {
                return x.first > y.first;
            }
            return x.second < y.second;
            });

        vector<int> ret;
        for (int i = 0; i < int(p.size()); i++) {
            for (int j = 0; j < p[i].second; j++) {
                ret.push_back(p[i].first);
            }
        }
        return ret;
    }
};