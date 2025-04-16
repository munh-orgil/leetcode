#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    long long countGood(vector<int>& a, int k) {
        long long n = a.size();
        unordered_map<int, int> cnt;
        int pt = 0, sum = 0;
        long long ret = 0;
        for (int i = 0; i < n; i++) {
            while (pt < n) {
                if (sum >= k) {
                    break;
                }
                sum += cnt[a[pt]];
                cnt[a[pt]]++;
                pt++;
            }
            if (sum >= k) ret += (n - pt + 1);
            else break;
            cnt[a[i]]--;
            sum -= cnt[a[i]];
        }
        return ret;
    }
};