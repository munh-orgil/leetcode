#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    string shiftingLetters(string s, vector<vector<int>>& p) {
        int n = s.size();
        vector<int> sum(n + 1, 0);
        for (vector<int>& a : p) {
            if (a[2] == 0) a[2] = -1;
            sum[a[0]] += a[2];
            sum[a[1] + 1] -= a[2];
        }
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur = (cur + sum[i]) % 26;
            s[i] = (s[i] - 'a' + cur + 26) % 26 + 'a';
        }
        return s;
    }
};