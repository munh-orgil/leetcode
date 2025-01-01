#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minimumPushes(string word) {
        int n = word.size();
        vector freq(26, 0);
        for (char ch : word) {
            freq[ch - 'a']++;
        }
        int ret = 0;
        sort(freq.rbegin(), freq.rend());
        for (int i = 0; i < 26; i++) {
            ret += ((i / 8) + 1) * freq[i];
        }
        return ret;
    }
};