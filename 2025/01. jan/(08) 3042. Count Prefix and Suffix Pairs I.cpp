#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int countPrefixSuffixPairs(vector<string>& s) {
        int n = s.size();
        int ret = 0;
        int a, b;
        for (int i = 0; i < n; i++) {
            a = s[i].size();
            for (int j = i + 1; j < n; j++) {
                b = s[j].size();
                if (a > b) continue;
                if (s[j].substr(0, a) == s[i] && s[j].substr(b - a, a) == s[i]) {
                    ret++;
                }
            }
        }
        return ret;
    }
};