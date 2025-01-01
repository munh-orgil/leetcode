#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> cnt(1001, 0);
        for (auto x : arr) {
            cnt[x]++;
        }
        for (auto x : target) {
            cnt[x]--;
        }
        for (auto x : cnt) {
            if (x) {
                return 0;
            }
        }
        return 1;
    }
};