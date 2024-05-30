#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int xorSum = 0;
        unordered_map<int, vector<int>> pos;
        pos[xorSum].push_back(0);
        for (int i = 0; i < n; i++) {
            xorSum = xorSum ^ arr[i];
            pos[xorSum].push_back(i + 1);
        }
        int ret = 0, sum, cnt;
        for (auto [k, v] : pos) {
            if (v.size() < 2) {
                continue;
            }
            sum = v[0];
            cnt = 1;
            for (int i = 1; i < v.size(); i++) {
                ret += cnt * v[i] - sum - cnt;
                cnt++;
                sum += v[i];
            }
        }
        return ret;
    }
};