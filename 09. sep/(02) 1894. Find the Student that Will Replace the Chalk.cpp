#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = accumulate(chalk.begin(), chalk.end(), 0LL);
        k %= sum;
        int n = chalk.size();
        for (int i = 0; i < n; i++) {
            if (chalk[i] < k) {
                return i;
            }
            k -= chalk[i];
        }
        return n - 1;
    }
};