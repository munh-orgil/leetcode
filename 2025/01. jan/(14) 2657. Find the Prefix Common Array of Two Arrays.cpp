#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> vis_a(n + 1, 0), vis_b(n + 1, 0), ret(n);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) cnt++;
            if (vis_a[b[i]] == 1) cnt++;
            if (vis_b[a[i]] == 1) cnt++;
            vis_a[a[i]] = 1;
            vis_b[b[i]] = 1;
            ret[i] = cnt;
        }
        return ret;
    }
};