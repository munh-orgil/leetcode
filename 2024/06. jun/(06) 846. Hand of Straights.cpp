#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize) {
            return false;
        }
        sort(hand.begin(), hand.end());
        vector<bool> vis(n, 0);
        int tmp, cur, idx;
        bool ok;
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                continue;
            }
            tmp = groupSize - 1;
            cur = hand[i];
            for (int j = i + 1; j < n && tmp; j++) {
                ok = 0;
                idx = lower_bound(hand.begin(), hand.end(), cur + 1) - hand.begin();
                for (int k = idx; k < n; k++) {
                    if (vis[k]) {
                        continue;
                    }
                    if (hand[k] == cur + 1) {
                        ok = 1;
                        vis[k] = 1;
                        cur++;
                        break;
                    }
                }
                if (!ok) {
                    return false;
                }
                tmp--;
            }
        }
        return true;
    }
};