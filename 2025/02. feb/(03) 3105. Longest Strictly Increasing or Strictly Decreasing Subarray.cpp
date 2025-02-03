#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int longestMonotonicSubarray(vector<int>& a) {
        int n = a.size();
        int x = 1, ret = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i - 1]) {
                x++;
            } else {
                x = 1;
            }
            ret = max(ret, x);
        }
        x = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                x++;
            } else {
                x = 1;
            }
            ret = max(ret, x);
        }
        return ret;
    }
};