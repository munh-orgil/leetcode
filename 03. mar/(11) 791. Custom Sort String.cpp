#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()

class Solution {
public:
    Solution() {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);
    }
    string customSortString(string order, string s) {
        vector<int> cnt(26, 0);
        for (char ch : s) {
            cnt[ch - 'a']++;
        }
        string ret = "";
        for (char ch : order) {
            for (; cnt[ch - 'a'] > 0; cnt[ch - 'a']--) {
                ret += ch;
            }
        }
        for (int i = 0; i < 26; i++) {
            for (; cnt[i] > 0; cnt[i]--) {
                ret += char('a' + i);
            }
        }
        return ret;
    }
};