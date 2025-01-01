#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    string toStr(int x) {
        string ret = "000";
        ret[0] += x / 100;
        ret[1] += (x / 10) % 10;
        ret[2] += x % 10;
        return ret;
    }
    int toInt(string s) {
        int ret = 0;
        for (int i = 0; i < s.size(); i++) {
            ret = ret * 10 + (s[i] - '0');
        }
        return ret;
    }
    string getStr(string s, int idx) {
        string ret = "";
        for (int i = 0; i < 3; i++) {
            ret += s[idx * 3 + i];
        }
        return ret;
    }
    string setStr(string s, string t, int idx) {
        s[idx * 3] = t[0];
        s[idx * 3 + 1] = t[1];
        s[idx * 3 + 2] = t[2];
        return s;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> cnt(26, 0);
        for (char ch : letters) {
            cnt[ch - 'a']++;
        }
        string str = "";
        for (int i = 0; i < 26; i++) {
            str += toStr(cnt[i]);
        }
        int n = words.size();
        vector<map<string, int>> dp(n + 1);
        dp[0][str] = 0;
        int ret = 0;
        for (int i = 0; i < n; i++) {
            vector<int> tmp(26, 0);
            for (int j = 0; j < words[i].size(); j++) {
                tmp[words[i][j] - 'a']++;
            }
            for (auto [k, v] : dp[i]) {
                dp[i + 1][k] = v;
                bool ok = 1;
                for (int j = 0; j < 26; j++) {
                    if (tmp[j] > toInt(getStr(k, j))) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                    string to = k;
                    for (int j = 0; j < 26; j++) {
                        if (!tmp[j]) continue;
                        v += score[j] * tmp[j];
                        to = setStr(to, toStr(toInt(getStr(to, j)) - tmp[j]), j);
                    }
                    dp[i + 1][to] = max(dp[i][to], v);
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            for (auto [k, v] : dp[i]) {
                ret = max(ret, v);
            }
        }
        return ret;
    }
};