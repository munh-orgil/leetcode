#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    string getHappyString(int n, int k) {
        int x = 3;
        for (int i = 1; i < n; i++) {
            x *= 2;
        }
        if (k > x) {
            return "";
        }
        string ret = "";
        int a = x / 3;
        int idx;
        if (k <= a) {
            idx = 0;
        } else if (k <= 2 * a) {
            idx = 1;
        } else {
            idx = 2;
        }
        k -= a * idx;
        ret += char('a' + idx);
        a /= 2;
        for (int i = 1; i < n; i++) {
            idx = 0;
            if (k > a) {
                idx++;
            }
            k -= a * idx;
            if (ret[i - 1] - 'a' <= idx) {
                idx++;
            }
            ret += char('a' + idx);
            a /= 2;
        }
        return ret;
    }
};