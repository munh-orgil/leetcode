#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    using PII = pair<int, int>;
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if (!n) return {};
        vector<int> ret(n);
        vector<PII> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = { arr[i], i };
        }
        sort(a.begin(), a.end());
        ret[a[0].second] = 1;
        int cur = 1;
        for (int i = 1; i < n; i++) {
            if (a[i].first > a[i - 1].first) {
                cur++;
            }
            ret[a[i].second] = cur;
        }
        return ret;
    }
};