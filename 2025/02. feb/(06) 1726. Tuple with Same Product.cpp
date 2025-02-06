#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int tupleSameProduct(vector<int>& a) {
        unordered_map<int, int> cnt;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                cnt[a[i] * a[j]]++;
            }
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ret += cnt[a[i] * a[j]] - 1;
            }
        }
        ret *= 4;
        return ret;
    }
};