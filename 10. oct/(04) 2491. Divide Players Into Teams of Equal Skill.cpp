#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    long long dividePlayers(vector<int>& a) {
        using ll = long long;
        int n = a.size();
        sort(a.begin(), a.end());
        int val = a.front() + a.back();
        long long ret = 0;
        for (int l = 0, r = n - 1; l < r; l++, r--) {
            if (a[l] + a[r] != val) {
                return -1;
            }
            ret += ll(a[l]) * ll(a[r]);
        }
        return ret;
    }
};