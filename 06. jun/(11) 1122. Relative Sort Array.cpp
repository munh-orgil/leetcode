#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> cnt(1001, 0);
        for (int x : arr1) {
            cnt[x]++;
        }
        vector<int> ret;
        for (int x : arr2) {
            while (cnt[x]) {
                ret.push_back(x);
                cnt[x]--;
            }
        }
        for (int i = 0; i <= 1000; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                ret.push_back(cnt[j]);
            }
        }
        return ret;
    }
};