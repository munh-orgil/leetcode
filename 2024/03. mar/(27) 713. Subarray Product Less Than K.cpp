#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()

class Solution {
public:
    Solution() {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);
    }
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0, prod;
        for (int i = 0; i < n; i++) {
            prod = 1;
            for (int j = i; j >= 0 && prod * nums[j] < k; j--) {
                prod *= nums[j];
                ans++;
            }
        }
        return ans;
    }
};