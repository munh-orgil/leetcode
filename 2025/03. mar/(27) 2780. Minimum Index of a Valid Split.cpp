#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minimumIndex(vector<int>& a) {
        int dom = 0;
        int n = a.size();
        unordered_map<int, int> cnt;
        for (int i : a) {
            cnt[i]++;
            if (cnt[i] * 2 > n) {
                dom = i;
            }
        }
        int r = cnt[dom], l = 0;
        for (int i = 0; i < n - 1; i++) {
            l += (a[i] == dom);
            r -= (a[i] == dom);
            if (l * 2 > i + 1 && r * 2 > n - i - 1) {
                return i;
            }
        }
        return -1;
    }
};