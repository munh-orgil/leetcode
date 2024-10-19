#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    char findKthBit(int n, int k) {
        k--;
        vector<string> s(n);
        s[0] = "0";
        int len = 1;
        for (int i = 1; i < n; i++) {
            if (len >= k) {
                s[i] = s[i - 1];
                continue;
            }
            s[i] = s[i - 1] + "1";
            for (int j = len - 1; j >= 0; j--) {
                s[i] += s[i - 1][j] ^ 1;
            }
            len = len * 2 + 1;
        }
        return s[n - 1][k];
    }
};