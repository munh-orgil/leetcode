#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    int numRabbits(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        int x = -1, cnt, ret = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == x && cnt > 0) {
                cnt--;
            } else {
                cnt = x = a[i];
                ret += a[i] + 1;
            }
        }
        return ret;
    }
};