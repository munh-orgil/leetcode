#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    long long coloredCells(long long n) {
        return 1 + (n * (n - 1)) * 2;
    }
};