#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int countPalindromicSubsequence(string s) {
        using PII = pair<int, int>;
        int n = s.size();
        vector<PII> pos(26, { -1, -1 });
        vector<vector<int>> cnt(n + 1, vector<int>(26, 0));
        for (int i = 0; i < n; i++) {
            if (pos[s[i] - 'a'].first == -1) pos[s[i] - 'a'].first = i;
            pos[s[i] - 'a'].second = i;
            cnt[i + 1] = cnt[i];
            cnt[i + 1][s[i] - 'a']++;
        }
        map<string, bool> mp;
        string t;
        char ch;
        for (int i = 0; i < 26; i++) {
            if (pos[i].first == pos[i].second) continue;
            ch = 'a' + i;
            for (int j = 0; j < 26; j++) {
                t = ch;
                if (cnt[pos[i].second + 1][j] - cnt[pos[i].first][j] > 0) {
                    t.push_back('a' + j);
                    t.push_back(ch);
                    mp[t] = 1;
                }
            }
        }
        for (auto [k, v] : mp) {
            cout << k << " ";
        }
        cout << endl;
        return mp.size();
    }
};