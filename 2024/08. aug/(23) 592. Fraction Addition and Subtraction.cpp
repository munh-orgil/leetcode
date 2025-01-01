#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int toInt(string s) {
        int ret = 0;
        for (char c : s) {
            ret = ret * 10 + c - '0';
        }
        return ret;
    }
    pair<int, int> toFraction(string s) {
        int a, b;
        int n = s.size();
        string t = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == '-') continue;
            if (s[i] == '/') {
                a = toInt(t);
                t = "";
                continue;
            }
            t += s[i];
        }
        if (s[0] == '-') {
            a *= -1;
        }
        b = toInt(t);
        cout << a << " " << b << endl;
        return { a, b };
    }
    int lcm(int x, int y) {
        return x / __gcd(x, y) * y;
    }
    string toString(int x) {
        if (!x) {
            return "0";
        }
        string ret = "";
        while (x) {
            ret += (x % 10) + '0';
            x /= 10;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    string fractionAddition(string s) {
        int n = s.size();
        vector<pair<int, int>> f;
        string t = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == '+') {
                f.push_back(toFraction(t));
                t = "";
                continue;
            }
            if (s[i] == '-') {
                if (t != "") {
                    f.push_back(toFraction(t));
                }
                t = "-";
                continue;
            }
            t += s[i];
        }
        f.push_back(toFraction(t));
        int a = 0, b = 1;
        for (auto [x, y] : f) {
            b = lcm(b, y);
        }
        for (auto [x, y] : f) {
            a += b / y * x;
        }
        int d = __gcd(a, b);
        if (d < 0) d *= -1;
        a /= d;
        b /= d;
        string ret = "";
        if (a < 0) {
            ret = "-";
            a *= -1;
        }
        ret += toString(a) + "/" + toString(b);
        return ret;
    }
};