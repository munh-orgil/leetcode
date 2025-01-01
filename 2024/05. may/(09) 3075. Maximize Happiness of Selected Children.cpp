#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ret = 0;
        sort(happiness.begin(), happiness.end(), greater());
        for (int i = 0; i < k; i++) {
            if (happiness[i] < i) {
                break;
            }
            ret += max(happiness[i] - i, 0);
        }
        return ret;
    }
};