#include<bits/stdc++.h>

using namespace std;

struct model {
    int id, pos, h;
    char dir;
};

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<model> a(n);
        for (int i = 0; i < n; i++) {
            a[i].id = i;
            a[i].pos = positions[i];
            a[i].h = healths[i];
            a[i].dir = directions[i];
        }
        sort(a.begin(), a.end(), [](model x, model y) {
            return x.pos < y.pos;
            });
        stack<model> st;
        vector<model> ans;
        model top;
        for (int i = 0; i < n; i++) {
            if (a[i].dir == 'R') {
                st.push(a[i]);
                continue;
            }
        again:;
            if (st.empty()) {
                ans.push_back(a[i]);
                continue;
            }
            top = st.top();
            st.pop();
            if (top.h < a[i].h) {
                a[i].h--;
                goto again;
            } else if (top.h > a[i].h) {
                top.h--;
                st.push(top);
            }
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        sort(ans.begin(), ans.end(), [](model x, model y) {
            return x.id < y.id;
            });
        int m = ans.size();
        vector<int> ret(m);
        for (int i = 0; i < m; i++) {
            ret[i] = ans[i].h;
        }
        return ret;
    }
};