#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    long long continuousSubarrays(vector<int>& a) {
        int n = a.size();
        multiset<int> st;
        int pt = 0;
        long long ret = 0;
        for (int i = 0; i < n; i++) {
            while (st.size() > 0 && (abs(a[i] - *st.begin()) > 2 || abs(a[i] - *st.rbegin()) > 2)) {
                st.erase(st.find(a[pt]));
                pt++;
            }
            st.insert(a[i]);
            ret += st.size();
        }
        return ret;
    }
};