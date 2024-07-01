#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int findCenter(vector<vector<int>>& edges) {
        map<int, int> cnt;
        for (auto edge : edges) {
            cnt[edge[0]]++;
            cnt[edge[1]]++;
        }
        int ret = 0;
        for (auto [k, v] : cnt) {
            if (v != 1) {
                ret = k;
                break;
            }
        }
        return ret;
    }
};