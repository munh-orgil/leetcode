#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (!grumpy[i]) {
                ret += customers[i];
            }
        }
        int sum = 0;
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i]) {
                sum += customers[i];
            }
        }
        int l;
        int ans = 0;
        for (int i = minutes; i < n; i++) {
            ans = max(ans, ret + sum);
            l = i - minutes;
            if (grumpy[l]) {
                sum -= customers[l];
            }
            if (grumpy[i]) {
                sum += customers[i];
            }
        }
        ans = max(ans, ret + sum);
        return ans;
    }
};