#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    bool canPartition(vector<int>& a) {
        int n = a.size();
        sort(a.rbegin(), a.rend());
        int sum = accumulate(a.begin(), a.end(), 0);
        if (sum % 2) return false;
        set<int> dp;
        vector<int> tmp;
        sum /= 2;
        dp.insert(0);
        for (int i = 0; i < n; i++) {
            tmp.clear();
            for (int x : dp) {
                tmp.push_back(x + a[i]);
                if (x + a[i] == sum) {
                    return true;
                }
            }
            for (int x : tmp) {
                dp.insert(x);
            }
        }
        return false;
    }
};