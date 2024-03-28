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
    int maxSubarrayLength(vector<int>& a, int k) {
        int n = a.size();
        unordered_map<int, int> cnt;
        int st = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cnt[a[i]]++;
            if (cnt[a[i]] > k) {
                for (; cnt[a[i]] > k; st++) {
                    cnt[a[st]]--;
                }
            }
            ans = max(ans, i - st + 1);
        }
        return ans;
    }
};