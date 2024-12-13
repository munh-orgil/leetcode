#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    long long findScore(vector<int>& a) {
        using PII = pair<int, int>;

        int n = a.size();
        vector<PII> p;
        for (int i = 0; i < n; i++) {
            p.push_back({ a[i], i });
        }
        sort(p.begin(), p.end());
        set<int> st;
        long long ret = 0;
        for (int i = 0; i < n; i++) {
            if (st.count(p[i].second)) {
                continue;
            }
            ret += p[i].first;
            st.insert(p[i].second - 1);
            st.insert(p[i].second);
            st.insert(p[i].second + 1);
        }
        return ret;
    }
};