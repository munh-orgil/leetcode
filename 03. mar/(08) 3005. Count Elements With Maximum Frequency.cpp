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
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(101, 0);
        int mx = 0;
        for (int num : nums) {
            mx = max(mx, ++cnt[num]);
        }
        int ret = 0;
        for (int num : nums) {
            if (cnt[num] == mx) {
                ret++;
            }
        }
        return ret;
    }
};