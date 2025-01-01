#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, bool> mp;
        for (int x : arr1) {
            while (x) {
                mp[x] = 1;
                x /= 10;
            }
        }
        int ret = 0;
        for (int x : arr2) {
            int tmp = x;
            int len = 0;
            while (tmp) {
                len++;
                tmp /= 10;
            }
            while (x) {
                if (mp[x]) {
                    ret = max(ret, len);
                }
                len--;
                x /= 10;
            }
        }
        return ret;
    }
};