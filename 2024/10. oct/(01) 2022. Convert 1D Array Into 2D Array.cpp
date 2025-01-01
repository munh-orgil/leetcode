#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> cnt(k + 1, 0);
        for (int i = 0; i < n; i++) {
            cnt[(arr[i] % k + k) % k]++;
        }
        if (cnt[0] % 2) return false;
        for (int i = 1; i < k; i++) {
            if (cnt[i] != cnt[k - i]) {
                return false;
            }
        }
        return true;
    }
};