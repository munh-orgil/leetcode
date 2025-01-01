#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> incl(26, 0);
        for (char c : allowed) {
            incl[c - 'a'] = 1;
        }
        int ret = 0;
        for (string word : words) {
            bool ok = 1;
            for (int i = 0; i < word.size(); i++) {
                ok &= incl[word[i] - 'a'];
            }
            ret += ok;
        }
        return ret;
    }
};