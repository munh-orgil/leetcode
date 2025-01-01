#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<string> split(string s) {
        string word = "";
        vector<string> ret;
        for (auto ch : s) {
            if (ch == ' ') {
                ret.push_back(word);
                word = "";
            }
            else {
                word += ch;
            }
        }
        ret.push_back(word);
        return ret;
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string, int> cnt;
        vector<string> ret;
        vector<string> sentence = split(s1);
        for (string s : sentence) {
            cnt[s]++;
        }
        sentence = split(s2);
        for (string s : sentence) {
            cnt[s]++;
        }
        for (auto [k, v] : cnt) {
            if (v == 1) {
                ret.push_back(k);
            }
        }
        return ret;
    }
};