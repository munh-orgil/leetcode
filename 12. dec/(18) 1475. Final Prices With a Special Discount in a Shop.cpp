#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> finalPrices(vector<int>& a) {
        int n = a.size();
        stack<int> st;
        vector<int> ret(n);
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() && st.top() > a[i]) {
                st.pop();
            }
            ret[i] = a[i];
            if (st.size()) {
                ret[i] -= st.top();
            }
            st.push(a[i]);
        }
        return ret;
    }
};