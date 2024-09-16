#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> t;
        int n = timePoints.size();
        for (string tp : timePoints) {
            int h = (tp[0] - '0') * 10 + (tp[1] - '0');
            int m = (tp[3] - '0') * 10 + (tp[4] - '0');
            t.push_back(h * 60 + m);
            t.push_back((h + 24) * 60 + m);
        }
        int ret = 1e9;
        sort(t.begin(), t.end());
        for (int i = 1; i < int(t.size()); i++) {
            ret = min(ret, t[i] - t[i - 1]);
        }
        return ret;
    }
};