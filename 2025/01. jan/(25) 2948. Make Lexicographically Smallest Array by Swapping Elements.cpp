#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> lexicographicallySmallestArray(vector<int>& a, int x) {
        using PII = pair<int, int>;
        int n = a.size();
        vector<PII> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = { a[i], i };
        }
        sort(b.begin(), b.end());
        vector<int> ret(n);
        multiset<int> pos, val;
        val.insert(b[0].first);
        pos.insert(b[0].second);
        auto f = [&]() {
            auto it1 = val.begin();
            auto it2 = pos.begin();
            for (int j = 0; j < pos.size(); j++) {
                ret[*it2] = *it1;
                it1++;
                it2++;
            }
            val.clear();
            pos.clear();
            };
        for (int i = 1; i < n; i++) {
            if (b[i].first - b[i - 1].first > x) {
                f();
            }
            val.insert(b[i].first);
            pos.insert(b[i].second);
        }
        f();
        return ret;
    }
};