#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int xorAllNums(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        int ret = 0;
        if (m % 2) {
            for (int i = 0; i < n; i++) {
                ret ^= a[i];
            }
        }
        if (n % 2) {
            for (int i = 0; i < m; i++) {
                ret ^= b[i];
            }
        }
        return ret;
    }
};