#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int largestCombination(vector<int>& a) {
        int n = a.size();
        int ret = 0;
        int b = 1;
        for (int i = 0; i <= 23; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (a[j] & b) {
                    cnt++;
                }
            }
            ret = max(ret, cnt);
            b *= 2;
        }
        return ret;
    }
};