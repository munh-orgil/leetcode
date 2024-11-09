#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    using ll = long long;
    vector<int> convert(int x) {
        vector<int> ret(60);
        int i = 59;
        while (x) {
            ret[i] = x % 2;
            x /= 2;
            i--;
        }
        return ret;
    }
    ll convert(vector<int>& vec) {
        ll ret = 0;
        for (int i = 0; i < 60; i++) {
            ret = ret * 2 + vec[i];
        }
        return ret;
    }
    ll minEnd(int n, int x) {
        auto a = convert(n);
        auto b = convert(x);
        int pt = 59;
        for (int i = 59; i >= 0; i--) {
            if (b[i] == 0) {
                b[i] = a[pt];
                pt--;
            }
        }
        return convert(b);
    }
};