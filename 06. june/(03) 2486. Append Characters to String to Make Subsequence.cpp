#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int appendCharacters(string s, string t) {
        int n = s.size();
        int m = t.size();
        int pt = 0;
        for (int i = 0; i < n; i++) {
            if (pt < m && s[i] == t[pt]) {
                pt++;
            }
        }
        return m - pt;
    }
};