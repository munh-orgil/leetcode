#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool canChange(string& s, string& t) {
        string a = "", b = "";
        int n = s.size();
        vector<int> l1, l2, r1, r2;
        for (int i = 0; i < n; i++) {
            if (s[i] != '_') {
                a += s[i];
            }
            if (s[i] == 'L') {
                l1.push_back(i);
            }
            if (s[i] == 'R') {
                r1.push_back(i);
            }
            if (t[i] != '_') {
                b += t[i];
            }
            if (t[i] == 'L') {
                l2.push_back(i);
            }
            if (t[i] == 'R') {
                r2.push_back(i);
            }
        }
        if (a != b) {
            return false;
        }
        for (int i = 0; i < l1.size(); i++) {
            if (l1[i] < l2[i]) {
                return false;
            }
        }
        for (int i = 0; i < r1.size(); i++) {
            if (r1[i] > r2[i]) {
                return false;
            }
        }
        return true;
    }
};