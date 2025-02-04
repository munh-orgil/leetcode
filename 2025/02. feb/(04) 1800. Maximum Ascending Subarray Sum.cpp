#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maxAscendingSum(vector<int>& a) {
        int n = a.size();
        int prev = 0;
        int sum = 0;
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] <= prev) {
                sum = 0;
            }
            sum += a[i];
            prev = a[i];
            ret = max(ret, sum);
        }
        return ret;
    }
};