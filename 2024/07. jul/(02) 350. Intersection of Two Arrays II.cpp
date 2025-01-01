#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<int> ret;
        int pt = 0;
        for (int i = 0; i < n; i++) {
            while (pt < m && a[i] > b[pt]) {
                pt++;
            }
            if (pt < m && a[i] == b[pt]) {
                ret.push_back(a[i]);
                pt++;
            }
        }
        return ret;
    }
};