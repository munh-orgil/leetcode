#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<vector<int>> mergeArrays(vector<vector<int>>& a, vector<vector<int>>& b) {
        unordered_map<int, int> sum;
        for (vector<int>& x : a) {
            sum[x[0]] += x[1];
        }
        for (vector<int>& x : b) {
            sum[x[0]] += x[1];
        }
        int n = 0;
        vector<vector<int>> ret;
        for (auto [k, v] : sum) {
            ret.push_back({ k, v });
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};