#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<string> split(const string& s) {
        vector<string> ret;
        int n = s.size();
        string word = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                ret.push_back(word);
                word = "";
                continue;
            }
            word += s[i];
        }
        ret.push_back(word);
        return ret;
    }
    bool areSentencesSimilar(string s, string t) {
        auto sen1 = split(s);
        auto sen2 = split(t);
        int n = sen1.size();
        int m = sen2.size();
        if (n > m) {
            swap(n, m);
            swap(sen1, sen2);
        }
        for (int i = 0; i <= n; i++) {
            bool ok = 1;
            for (int j = 0; j < i; j++) {
                if (sen1[j] != sen2[j]) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) {
                continue;
            }
            for (int j = 0; j < n - i; j++) {
                if (sen1[n - j - 1] != sen2[m - n + i + j]) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                return true;
            }
        }
        return false;
    }
};
