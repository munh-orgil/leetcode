#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    string addSpaces(const string& s, vector<int>& a) {
        int n = s.size();
        int pt = 0;
        string ret = "";
        for (int i = 0; i < n; i++) {
            if (pt < a.size() && a[pt] == i) {
                ret += ' ';
                pt++;
            }
            ret += s[i];
        }
        return ret;
    }
};