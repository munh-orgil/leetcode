#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool canBeValid(string& s, string& t) {
        int n = s.size();
        if (n % 2) return false;
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') a++;
            else a--;
            if (t[i] == '0' && s[i] == ')') b++;
            if (a < 0) {
                if (b <= 0) {
                    return false;
                }
                a += 2;
                b--;
            }
        }
        a = 0, b = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')') a++;
            else a--;
            if (t[i] == '0' && s[i] == '(') b++;
            if (a < 0) {
                if (b <= 0) {
                    return false;
                }
                a += 2;
                b--;
            }
        }
        return true;
    }
};