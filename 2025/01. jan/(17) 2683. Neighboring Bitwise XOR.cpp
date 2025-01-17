#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool doesValidArrayExist(vector<int>& a) {
        int n = a.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum ^= a[i];
        }
        return sum == 0;
    }
};