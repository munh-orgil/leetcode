#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int findLengthOfShortestSubarray(vector<int>& a) {
        int n = a.size();
        if (is_sorted(a.begin(), a.end())) {
            return 0;
        }
        vector<int> p, q;
        for (int i = 0; i < n - 1; i++) {
            p.push_back(a[i]);
            if (a[i] > a[i + 1]) break;
        }
        for (int i = n - 1; i > 0; i--) {
            q.push_back(a[i]);
            if (a[i] < a[i - 1]) break;
        }
        reverse(q.begin(), q.end());
        int ret = n - max(p.size(), q.size());
        int pt = 0;
        int m = q.size();
        for (int i = 0; i < p.size(); i++) {
            if (p[i] > q.back()) {
                break;
            }
            while (p[i] > q[pt]) {
                pt++;
            }
            ret = min(ret, n - (i + 1 + (m - pt)));
        }
        return ret;
    }
};