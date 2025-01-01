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
    int subarraysWithKDistinct(std::vector<int>& nums, int k) {
        return subarraysWithAtMostKDistinct(nums, k) - subarraysWithAtMostKDistinct(nums, k - 1);
    }
    int subarraysWithAtMostKDistinct(std::vector<int>& nums, int k) {
        int ans = 0;
        std::vector<int> count(nums.size() + 1, 0);

        int l = 0;
        for (int r = 0; r < nums.size(); ++r) {
            if (++count[nums[r]] == 1)
                --k;
            while (k == -1) {
                if (--count[nums[l++]] == 0)
                    ++k;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};