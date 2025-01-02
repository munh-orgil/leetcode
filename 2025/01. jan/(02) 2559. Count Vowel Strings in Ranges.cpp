#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    const string vowels = "aeiou";
    bool isVowel(char ch) {
        for (int i = 0; i < 5; i++) {
            if (ch == vowels[i]) return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cnt[i + 1] = cnt[i] + (isVowel(s[i][0]) && isVowel(s[i].back()));
        }
        vector<int> ret;
        for (auto q : queries) {
            ret.push_back(cnt[q[1] + 1] - cnt[q[0]]);
        }
        return ret;
    }
};