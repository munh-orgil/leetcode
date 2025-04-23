#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    int countLargestGroup(int n) {
        int x, sum;
        vector<int> cnt(40, 0);
        for (int i = 1; i <= n; i++) {
            x = i;
            sum = 0;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            cnt[sum]++;
        }
        int mx = 0, ret = 0;
        for (int i = 0; i < 40; i++) {
            if (cnt[i] > mx) {
                mx = cnt[i];
                ret = 1;
            } else if (cnt[i] == mx) {
                ret++;
            }
        }
        return ret;
    }
};