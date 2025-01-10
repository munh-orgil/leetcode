#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> count(string& s) {
        vector<int> ret(26, 0);
        for (char ch : s) {
            ret[ch - 'a']++;
        }
        return ret;
    }
    vector<string> wordSubsets(vector<string>& s1, vector<string>& s2) {
        vector<int> mx(26, 0), cnt(26, 0);
        for (string& s : s2) {
            cnt = count(s);
            for (int i = 0; i < 26; i++) {
                mx[i] = max(mx[i], cnt[i]);
            }
        }
        vector<string> ret;
        for (string& s : s1) {
            cnt = count(s);
            bool ok = 1;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] < mx[i]) {
                    ok = 0;
                    break;
                }
            }
            if (ok) ret.push_back(s);
        }
        return ret;
    }
};