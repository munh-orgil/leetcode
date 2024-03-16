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
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> first;
        int sum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i]) {
                sum++;
            }
            else {
                sum--;
            }
            if (sum && !first[sum]) {
                first[sum] = i + 1;
            }
            else {
                ans = max(ans, i + 1 - first[sum]);
            }
        }
        return ans;
    }
};