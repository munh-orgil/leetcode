#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    int minimumOperations(vector<int>& a) {
        int n = a.size();
        vector<int> cnt(101, 0);
        for (int i : a) {
            cnt[i]++;
        }
        int x = 0;
        for (int i = 0; i <= 100; i++) {
            if (cnt[i] > 1) x++;
        }
        for (int i = 0; i < (n + 2) / 3; i++) {
            if (!x) return i;
            for (int j = 3 * i; j < min(3 * i + 3, n); j++) {
                cnt[a[j]]--;
                if (cnt[a[j]] == 1) x--;
            }
        }
        return (n + 2) / 3;
    }
};