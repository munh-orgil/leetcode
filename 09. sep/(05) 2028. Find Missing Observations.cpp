#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        int m = rolls.size();
        int total = mean * (n + m);
        int missing = total - sum;
        vector<int> ret;
        if (n > missing || n * 6 < missing) {
            return ret;
        }
        ret = vector<int> (n);
        int x = missing / n;
        int r = missing % n;
        for (int i = 0; i < n; i++) {
            if (i < r) {
                ret[i] = x + 1;
            }
            else {
                ret[i] = x;
            }
        }
        return ret;
    }
};