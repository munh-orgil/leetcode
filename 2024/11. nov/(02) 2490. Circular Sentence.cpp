#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool isCircularSentence(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ' && (s[i - 1] != s[i + 1])) {
                return false;
            }
        }
        return s[0] == s[n - 1];
    }
};