#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int waysToSplitArray(vector<int>& a) {
        int n = a.size();
        long long r = accumulate(a.begin(), a.end(), 0LL);
        long long l = 0;
        int ret = 0;
        for (int i = 0; i < n - 1; i++) {
            l += a[i];
            r -= a[i];
            if (l >= r) {
                ret++;
            }
        }
        return ret;
    }
};