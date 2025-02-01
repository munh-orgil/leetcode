#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool isArraySpecial(vector<int>& a) {
        int n = a.size();
        for (int i = 1; i < n; i++) {
            if (a[i] % 2 == a[i - 1] % 2) {
                return false;
            }
        }
        return true;
    }
};