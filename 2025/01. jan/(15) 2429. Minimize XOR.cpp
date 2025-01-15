#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> convert(int x) {
        vector<int> ret;
        while (x) {
            ret.push_back(x % 2);
            x /= 2;
        }
        return ret;
    }
    int convert(vector<int>& v) {
        int ret = 0;
        for (int i = v.size() - 1; i >= 0; i--) {
            ret = 2 * ret + v[i];
        }
        return ret;
    }
    int minimizeXor(int num1, int num2) {
        vector<int> a, b, c;
        a = convert(num1);
        b = convert(num2);
        c.assign(max(a.size(), b.size()), 0);
        int cnt = accumulate(b.begin(), b.end(), 0);
        for (int i = 0; i < cnt; i++) {
            c[i] = 1;
        }
        int r = a.size() - 1;
        int l = cnt - 1;
        while (l < r) {
            if (l < 0 || r < 0) break;
            if (a[r] == 0) {
                r--;
                continue;
            }
            c[r] = 1;
            c[l] = 0;
            l--;
            r--;
        }
        return convert(c);
    }
};