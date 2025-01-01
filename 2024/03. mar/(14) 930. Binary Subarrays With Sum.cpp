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
    int numSubarraysWithSum(vector<int>& a, int goal) {
        int n = a.size();
        vector<int> cnt(n, 0);
        int sum = 0;
        for (int elem : a) {
            sum += elem;
            cnt[sum]++;
        }
        int ans = 0;
        if (!goal) {
            for (int i = 0; i < n; i++) {
                ans += cnt[i] * (cnt[i] + 1) / 2;
            }
            return ans;
        }
        for (int i = goal; i < n; i++) {
            ans += cnt[i] * cnt[i - goal];
            cout << i << " " << ans << endl;
        }
        return ans;
    }
};