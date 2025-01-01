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
    int subarraysWithKDistinct(vector<int>& a, int k) {
        int n = a.size();
        vector<int> cnt(n + 1, 0);
        int dis = 0;
        int st = 0;
        int ok = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!cnt[a[i]]) {
                dis++;
            }
            if (dis == k) {
                ok++;
            }
            if (dis > k) {
                for (; cnt[a[st]] > 1; st++) {
                    ans += ok;
                    cnt[st]--;
                }
                dis = k;
                ok = 1;
            }
            cnt[a[i]]++;
        }
        ans += ok;
        return ans;
    }
};