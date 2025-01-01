#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<string, int> dp;
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> a(n, -1);
        for (auto e : edges) {
            a[e[1]] = 0;
        }
        int ret = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                if (ret == -1) {
                    ret = i;
                } else {
                    return -1;
                }
            }
        }
        return ret;
    }
};