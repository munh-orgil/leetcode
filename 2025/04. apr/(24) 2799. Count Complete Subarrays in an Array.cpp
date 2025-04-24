#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    int countCompleteSubarrays(vector<int>& a) {
        int n = a.size();
        unordered_map<int, int> cnt, mp;
        for (int i : a) {
            cnt[i]++;
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            mp.clear();
            for (int r = n - 1; r >= i; r--) {
                mp[a[r]]++;
                if (mp[a[r]] == cnt[a[r]]) {
                    ret += (n - r);
                    break;
                }
            }
            cnt[a[i]]--;
            if (!cnt[a[i]]) {
                break;
            }
        }
        return ret;
    }
};