#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> smallestRange(vector<vector<int>>& a) {
        int k = a.size();
        set<int> st;
        for (const auto v : a) {
            for (const int x : v) {
                st.insert(x);
            }
        }
        vector<int> pt(k, 0);
        int d = INT_MAX;
        int l, r;
        int mn, mx;
        for (int x : st) {
            mn = x;
            mx = x;
            for (int i = 0; i < k; i++) {
                while (pt[i] < a[i].size() && a[i][pt[i]] < x) {
                    pt[i]++;
                }
                if (pt[i] == a[i].size()) {
                    return { l, r };
                }
                mx = max(mx, a[i][pt[i]]);
            }
            if (mx - mn < d) {
                d = mx - mn;
                l = mn;
                r = mx;
            }
        }
        return { l, r };
    }
};
