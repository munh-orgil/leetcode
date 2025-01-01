#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maximumBeauty(vector<int>& a, int k) {
        int n = a.size();
        sort(a.begin(), a.end());
        int pt = 0;
        int ret = 0;
        for (int i = 0; i < n; i++) {
            while (pt < n && a[i] + 2 * k >= a[pt]) {
                pt++;
            }
            ret = max(ret, pt - i);
        }
        return ret;
    }
};