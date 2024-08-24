#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    long long toNum(string s, int l, int r) {
        long long ret = 0;
        for (int i = l; i < r; i++) {
            ret = ret * 10 + (s[i] - '0');
        }
        return ret;
    }
    string toString(long long x) {
        if (!x) return "0";
        string ret = "";
        while (x) {
            ret += (x % 10) + '0';
            x /= 10;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    string nearestPalindromic(string s) {
        int n = s.size();
        string x = s;
        for (int i = 0; i < n; i++) {
            x[n - i - 1] = x[i];
        }
        string y;
        long long a = toNum(x, 0, n);
        long long b = toNum(s, 0, n);
        long long l = a, r = a;
        int m;
        long long p = toNum(x, 0, (n + 1) / 2);
        if (a >= b) {
            if (pow(10, int(log10(p))) == p) {
                l = 0;
                while (l * 10 + 9 < a) {
                    l = l * 10 + 9;
                }
            } else {
                l = p - 1;
                if (l) {
                    while (l < INT64_MAX / 10 && l * 10 < a) {
                        l *= 10;
                    }
                    y = toString(l);
                    m = y.size();
                    for (int i = 0; i < m; i++) {
                        y[m - i - 1] = y[i];
                    }
                    l = toNum(y, 0, m);
                }
            }
        }
        if (a <= b) {
            r = p + 1;
            while (r < a) {
                r *= 10;
            }
            y = toString(r);
            m = y.size();
            for (int i = 0; i < m; i++) {
                y[m - i - 1] = y[i];
            }
            r = toNum(y, 0, m);
        }
        if (b - l <= r - b) {
            return toString(l);
        }
        return toString(r);
    }
};