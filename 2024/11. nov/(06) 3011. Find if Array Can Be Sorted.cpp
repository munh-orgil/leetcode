#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool canSortArray(vector<int>& a) {
        int n = a.size();
        vector<int> b(n), mx(n + 1, 0), mn(n + 1, 1e9);
        for (int i = 0; i < n; i++) {
            while (a[i]) {
                b[i] += (a[i] % 2);
                a[i] /= 2;
            }
        }
        for (int i = 0; i < n; i++) {
            mx[i + 1] = max(mx[i], a[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            mn[i] = min(mn[i + 1], a[i]);
        }
        for (int i = 1; i < n; i++) {
            if (b[i] != b[i - 1]) {
                if (b[i - 1] > b[i] || mx[i - 1] > mn[i + 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};