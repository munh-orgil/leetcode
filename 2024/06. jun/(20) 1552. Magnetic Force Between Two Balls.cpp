#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int r = position[n - 1] - position[0], l = 1;
        int mid, cnt, cur, ans;
        while (l <= r) {
            mid = (l + r) / 2;
            cnt = 1;
            cur = position[0];
            for (int i = 1; i < n; i++) {
                if (position[i] - cur >= mid) {
                    cnt++;
                    cur = position[i];
                }
            }
            if (cnt >= m) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};