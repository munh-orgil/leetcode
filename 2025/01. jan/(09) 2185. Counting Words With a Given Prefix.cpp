#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int prefixCount(vector<string>& a, string t) {
        int n = t.size();
        int ret = 0;
        for (string& s : a) {
            ret += (t == (s.substr(0, n)));
        }
        return ret;
    }
};