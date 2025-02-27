#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int lenLongestFibSubseq(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n, 1);
        set<int> st(a.begin(), a.end());
        int ret = 0;
        int x, y, z, cnt;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                x = a[i];
                y = a[j];
                z = x + y;
                cnt = 0;
                while (st.find(z) != st.end()) {
                    cnt++;
                    x = y;
                    y = z;
                    z = x + y;
                }
                if (cnt > 0) {
                    ret = max(ret, cnt + 2);
                }
            }
        }
        return ret;
    }
};