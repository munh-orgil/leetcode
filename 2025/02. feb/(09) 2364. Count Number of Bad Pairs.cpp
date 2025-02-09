#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    long long countBadPairs(vector<int>& a) {
        int n = a.size();
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            a[i] -= i;
            cnt[a[i]]++;
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            ret += n - i - cnt[a[i]];
            cnt[a[i]]--;
        }
        return ret;
    }
};