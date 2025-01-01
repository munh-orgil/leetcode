#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool canMakeSubsequence(string s, string t) {
        int n = s.size();
        int i = 0;
        for (char& c : t) {
            while (i < n && s[i] != c && char((s[i] - 'a' + 1) % 26 + 'a') != c) {
                i++;
            }
            if (i == n) {
                return false;
            }
            i++;
        }
        return true;
    }
};