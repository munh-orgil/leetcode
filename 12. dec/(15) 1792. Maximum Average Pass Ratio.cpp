#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    double maxAverageRatio(vector<vector<int>>& a, int e) {
        using PII = pair<int, int>;
        int n = a.size();
        auto cmp = [](PII x, PII y) {
            return (x.second - x.first) / (x.second * (x.second + 1.0)) > (y.second - y.first) / (y.second * (y.second + 1.0));
            };
        multiset<PII, decltype(cmp)> st;
        for (vector<int>& v : a) {
            st.insert(PII{ v[0], v[1] });
        }
        for (int i = 0; i < e; i++) {
            PII p = *st.begin();
            st.erase(st.begin());
            st.insert({ p.first + 1, p.second + 1 });
        }
        double ret = 0;
        for (auto [f, s] : st) {
            ret += (double(f) / double(s));
        }
        ret /= n;
        return ret;
    }
};