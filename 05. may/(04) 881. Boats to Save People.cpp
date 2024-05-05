#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int numRescueBoats(vector<int>& people, int limit) {
        int n, ret, idx, bound;
        n = people.size();
        sort(people.begin(), people.end());
        vector<bool> vis(n, 0);
        ret = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (vis[i]) {
                continue;
            }
            vis[i] = 1;
            bound = limit - people[i];
            auto end = people.begin() + i;
            idx = upper_bound(people.begin(), end, bound) - people.begin();
            while(idx >= 0 && (people[idx] > bound || vis[idx])) {
                idx--;
            }
            if (idx != -1) {
                vis[idx] = 1;
            }
            ret++;
        }
        return ret;
    }
};