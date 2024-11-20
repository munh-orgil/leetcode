#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int takeCharacters(string s, int k) {
        int n = s.size();
        vector<vector<int>> pre(n + 1, vector<int> (3, 0));
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i];
            pre[i + 1][s[i] - 'a']++;
        }
        vector<int> cnt(3, 0);
        int pt = n, ret = 1e9;
        for (int i = n; i >= 0; i--) {
            if (pt < 0) break;
            pt = min(pt, i);
            bool ok = 1;
            while (ok && pt >= 0) {
                for (int j = 0; j < 3; j++) {
                    if (cnt[j] + pre[pt][j] < k) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                    ret = min(ret, n - i + pt);
                    pt--;
                }
            }
            if (i) {
                cnt[s[i - 1] - 'a']++;
            }
        }
        return (ret == 1e9 ? -1 : ret);
    }
};