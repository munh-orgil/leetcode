#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        vector<int> x;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                x.push_back(i);
            }
        }
        int m = x.size();
        if (!m) {
            return true;
        }
        if (m != 2) {
            return false;
        }
        return (s1[x[0]] == s2[x[1]] && s1[x[1]] == s2[x[0]]);
    }
};