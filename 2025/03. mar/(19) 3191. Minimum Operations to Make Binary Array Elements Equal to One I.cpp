#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minOperations(vector<int>& a) {
        int n = a.size();
        int ret = 0;
        for (int i = 0; i < n - 2; i++) {
            if (a[i]) continue;
            ret++;
            for (int j = 0; j < 3; j++) {
                a[i + j] ^= 1;
            }
        }
        if (!a[n - 2] || !a[n - 1]) {
            return -1;
        }
        return ret;
    }
};