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
        for (int i = 1; i <= time; i++) {
            cout << n - abs(time - 1 - n) << " ";
        }
        return 0;
    }
};