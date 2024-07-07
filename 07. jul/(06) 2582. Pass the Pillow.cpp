#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int passThePillow(int n, int time) {
        time %= (2 * n - 2);
        return n - abs(time - 1 - n);
    }
};