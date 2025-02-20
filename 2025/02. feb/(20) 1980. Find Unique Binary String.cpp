#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    string findDifferentBinaryString(vector<string>& a) {
        unordered_set<string> st(a.begin(), a.end());
        int n = a.size();
        string s;
        for (int i = 0; i < (1 << n); i++) {
            s = "";
            for (int j = 0; j < n; j++) {
                s.push_back(char('0' + (i & (1 << j) > 0)));
            }
            if (st.find(s) == st.end()) {
                return s;
            }
        }
        return "";
    }
};