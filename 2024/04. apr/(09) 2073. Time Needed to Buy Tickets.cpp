#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int ret = (tickets[k] - 1) * n + k + 1;
        for (int i = 0; i < n; i++) {
            if (tickets[i] < tickets[k]) {
                ret -= (tickets[k] - tickets[i]);
                if (i > k) {
                    ret++;
                }
            }
        }
        return ret;
    }
};
