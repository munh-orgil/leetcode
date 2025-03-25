#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool checkValidCuts(int n, vector<vector<int>>& rec) {
        int sz = rec.size();
        auto check = [&]() -> bool {
            sort(rec.begin(), rec.end());
            int cnt = 0, r = rec[0][2];
            for (int i = 1; i < sz; i++) {
                if (rec[i][0] >= r) {
                    cnt++;
                }
                r = max(r, rec[i][2]);
            }
            return cnt >= 2;
            };
        if (check()) {
            return true;
        }
        for (int i = 0; i < sz; i++) {
            swap(rec[i][0], rec[i][1]);
            swap(rec[i][2], rec[i][3]);
        }
        return check();
    }
};