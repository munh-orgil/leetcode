#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int last = 0;
        int ret = 0;
        for (vector<int>& m : meetings) {
            if (m[0] > last) {
                ret += m[0] - last - 1;
            }
            last = max(last, m[1]);
        }
        ret += days - last;
        return ret;
    }
};