#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        map<int, int> cnt;
        cnt[nums[0]] = 1;
        int mx, mn;
        int l = 0;
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            cnt[nums[i]]++;
            mn = cnt.begin()->first;
            mx = prev(cnt.end())->first;
            while (mx - mn > limit) {
                cnt[nums[l]]--;
                if (!cnt[nums[l]]) {
                    cnt.erase(cnt.find(nums[l]));
                }
                mn = cnt.begin()->first;
                mx = prev(cnt.end())->first;
                l++;
            }
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};