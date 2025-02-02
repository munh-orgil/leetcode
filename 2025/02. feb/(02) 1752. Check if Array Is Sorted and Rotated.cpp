#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool check(vector<int>& a) {
        int n = a.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += (a[i] > a[(i + 1) % n]);
        }
        return cnt <= 1;
    }
};