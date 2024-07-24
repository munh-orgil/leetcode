#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            vector<int> d;
            if (!num) {
                d = { 0 };
            }
            while (num) {
                d.push_back(num % 10);
                num /= 10;
            }
            int x = 0;
            for (int j = int(d.size()) - 1; j >= 0; j--) {
                x = x * 10 + mapping[d[j]];
            }
            a[i].first = x;
            a[i].second = nums[i];
        }
        sort(a.begin(), a.end(), [&](pair<int, int> x, pair<int, int> y) {
            return x.first < y.first;
            });
        vector<int> ret(n);
        for (int i = 0; i < n; i++) {
            ret[i] = a[i].second;
        }
        return ret;
    }
};