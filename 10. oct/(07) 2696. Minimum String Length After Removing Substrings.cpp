#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool check(char a, char b) {
        return (a == 'A' && b == 'B') || (a == 'C' && b == 'D');
    }
    int minLength(string s) {
        int n = s.size();
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            int l = i;
            int r = i + 1;
            while (l >= 0 && r < n) {
                if (vis[l]) {
                    l--;
                    continue;
                }
                if (vis[r]) {
                    r++;
                    continue;
                }
                if (check(s[l], s[r])) {
                    vis[l] = 1;
                    vis[r] = 1;
                    l--; r++;
                    continue;
                }
                break;
            }
        }
        int ret = n - accumulate(vis.begin(), vis.end(), 0);
        return ret;
    }
};
