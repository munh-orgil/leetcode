#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int sum(int x) {
        int ret = 0;
        while (x) {
            ret += x % 10;
            x /= 10;
        }
        return ret;
    }
    int maximumSum(vector<int>& a) {
        vector<vector<int>> x(100);
        int n = a.size();
        for (int i = 0; i < n; i++) {
            x[sum(a[i])].push_back(a[i]);
        }
        int ret = -1;
        for (int i = 0; i < 100; i++) {
            if (x[i].size() >= 2) {
                sort(x[i].rbegin(), x[i].rend());
                ret = max(ret, x[i][0] + x[i][1]);
            }
        }
        return ret;
    }
};