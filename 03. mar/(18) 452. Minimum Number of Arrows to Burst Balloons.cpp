#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()

class Solution {
public:
    Solution() {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);
    }
    int findMinArrowShots(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        int ret = 0;
        int mx = a[0][1];
        for (int i = 0; i < n; i++) {
            for (; i < n && a[i][0] <= mx; i++) {
                mx = min(mx, a[i][1]);
            }
            ret++;
            if (i < n) {
                mx = a[i][1];
            }
            i--;
        }
        return ret;
    }
};