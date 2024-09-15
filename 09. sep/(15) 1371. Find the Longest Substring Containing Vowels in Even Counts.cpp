#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int findTheLongestSubstring(string s) {
        string vowels = "aeiou";
        int n = s.size();
        vector<int> a(n + 1, 0);
        vector bin = { 16, 8, 4, 2, 1 };
        vector<int> l(32, -1), r(32, -1);
        int vow;
        l[0] = 0;
        for (int i = 0; i < n; i++) {
            vow = vowels.find(s[i]);
            if (vow == -1) {
                a[i + 1] = a[i];
            }
            else {
                a[i + 1] = a[i] ^ bin[vow];
            }
            if (l[a[i + 1]] == -1) {
                l[a[i + 1]] = i + 1;
            }
            else {
                r[a[i + 1]] = i + 1;
            }
        }
        int ret = 0;
        for (int i = 0; i < 32; i++) {
            ret = max(ret, r[i] - l[i]);
        }
        return ret;
    }
};