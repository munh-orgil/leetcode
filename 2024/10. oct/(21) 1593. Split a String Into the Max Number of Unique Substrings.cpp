#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maxUniqueSplit(string s) {
        int n = s.size();
        int ret = 0;
        string t;
        for (int i = 0; i < (1 << n); i++) {
            set<string> st;
            t = "";
            bool ok = 1;
            for (int j = 0; j < n; j++) {
                t += s[j];
                if (i & (1 << j)) {
                    if (st.find(t) != st.end()) {
                        ok = 0;
                        break;
                    }
                    st.insert(t);
                    t = "";
                }
            }
            if (ok) {
                ret = max(ret, int(st.size()));
            }
        }
        return ret;
    }
};