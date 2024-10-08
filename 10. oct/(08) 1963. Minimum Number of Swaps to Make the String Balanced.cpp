#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minSwaps(string s) {
        int n = s.size();
        int cnt = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            cnt += (s[i] == '[' ? 1 : -1);
            mx = max(-cnt, mx);
        }
        return (cnt + 1) / 2;
    }
};
