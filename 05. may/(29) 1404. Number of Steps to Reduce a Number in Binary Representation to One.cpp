#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    int numSteps(string s) {
        int n = s.size();
        int ret = 0;
        vector<char> a(s.rbegin(), s.rend());
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == '1') {
                ret++;
                int idx = i;
                while (idx < a.size() && a[idx] == '1') {
                    a[idx] = '0';
                    idx++;
                }
                if (idx == a.size()) {
                    a.push_back('0');
                }
                a[idx]++;
            }
            ret++;
        }
        return ret;
    }
};