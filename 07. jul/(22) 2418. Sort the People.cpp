#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = { heights[i], names[i] };
        }
        sort(a.rbegin(), a.rend());
        vector<string> ret(n);
        for (int i = 0; i < n; i++) {
            ret[i] = a[i].second;
        }
        return ret;
    }
};