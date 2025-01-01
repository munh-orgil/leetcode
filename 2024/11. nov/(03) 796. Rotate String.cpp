#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool rotateString(string s, string goal) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            bool ok = 1;
            for (int j = 0; j < n; j++) {
                if (s[(i + j) % n] != goal[j]) {
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