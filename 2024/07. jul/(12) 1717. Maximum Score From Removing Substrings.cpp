#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    pair<int, stack<char>> count(string s, int x, string match) {
        stack<char> st;
        int n = s.size();
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                st.push(s[i]);
                continue;
            }
            if (st.top() == match[0] && s[i] == match[1]) {
                ret += x;
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        return { ret, st };
    }
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        int ret = 0;
        pair<int, stack<char>> p;
        if (x >= y) {
            p = count(s, x, "ab");
        } else {
            p = count(s, y, "ba");
        }
        string t = "";
        while (!p.second.empty()) {
            t += p.second.top();
            p.second.pop();
        }
        reverse(t.begin(), t.end());
        ret = p.first;
        if (x >= y) {
            p = count(t, y, "ba");
        } else {
            p = count(t, x, "ab");
        }
        ret += p.first;
        return ret;
    }
};