#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool check(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    string shortestPalindrome(string s) {
        int n = s.size();
        int idx;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == s[0]) {
                if (check(s, 0, i)) {
                    idx = i;
                    break;
                }
            }
        }
        string ret = "";
        for (int i = n - 1; i > idx; i--) {
            ret += s[i];
        }
        ret += s;
        return ret;
    }
};