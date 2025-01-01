#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<int> cnt(26, INT_MAX);
        for (int i = 0; i < n; i++) {
            vector<int> tmp(26, 0);
            for (char c : words[i]) {
                tmp[c - 'a']++;
            }
            for (int j = 0; j < 26; j++) {
                cnt[i] = min(cnt[i], tmp[j]);
            }
        }
        vector<string> ret;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == INT_MAX) {
                continue;
            }
            string s = "";
            s += 'a' + i;
            for (int j = 0; j < cnt[i]; j++) {
                ret.push_back(s);
            }
        }
        return ret;
    }
};