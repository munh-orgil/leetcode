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
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        int n = a.size();
        if (!n) {
            return { b };
        }
        int start = b[0], end = b[1], i;
        a.push_back({ start, end });
        vector<vector<int>> ret;
        for (i = 0; i < n && a[i][1] < start; i++) {
            ret.push_back(a[i]);
        }
        int newSt = min(start, a[i][0]);
        int newEnd = end;
        for (; i < n && a[i][0] <= end; i++) {
            newEnd = max(end, a[i][1]);
        }
        ret.push_back({ newSt, newEnd });
        for (; i < n; i++) {
            ret.push_back(a[i]);
        }
        return ret;
    }
};