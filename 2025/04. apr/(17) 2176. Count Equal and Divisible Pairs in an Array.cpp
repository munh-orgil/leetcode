#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    int countPairs(vector<int>& a, int k) {
        int n = a.size();
        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((a[i] == a[j]) && (i * j) % k == 0) ret++;
            }
        }
        return ret;
    }
};