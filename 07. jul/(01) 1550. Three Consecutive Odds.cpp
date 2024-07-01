#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool threeConsecutiveOdds(vector<int>& arr) {
        for (int i = 0; i < int(arr.size()) - 2; i++) {
            if (arr[i] % 2 && arr[i + 1] % 2 && arr[i + 2] % 2) {
                return true;
            }
        }
        return false;
    }
};