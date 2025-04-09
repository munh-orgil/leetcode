#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    int minOperations(vector<int>& a, int k) {
        int n = a.size();
        int mn = *min_element(a.begin(), a.end());
        if (mn < k) {
            return -1;
        }
        int ret = mn != k;
        set<int> st(a.begin(), a.end());
        ret += (st.size() - 1);
        return ret;
    }
};