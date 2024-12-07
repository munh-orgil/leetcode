#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maxCount(vector<int>& a, int n, int sum) {
        sort(a.begin(), a.end());
        int pt = 0;
        int ret = 0;
        for (int i = 1; i <= n; i++) {
            while (pt < a.size() && i > a[pt]) {
                pt++;
            }
            if (pt < a.size() && i == a[pt]) {
                pt++;
                continue;
            }
            if (i <= sum) {
                ret++;
                sum -= i;
            }
        }
        return ret;
    }
};