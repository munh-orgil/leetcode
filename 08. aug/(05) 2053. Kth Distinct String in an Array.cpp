#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();
        unordered_map<string, int> cnt;
        for (int i = 0; i < n; i++) {
            cnt[arr[i]]++;
        }
        for (int i = 0; i < n; i++) {
            if (cnt[arr[i]] == 1) {
                k--;
                if (!k) {
                    return arr[i];
                }
            }
        }
        return "";
    }
};