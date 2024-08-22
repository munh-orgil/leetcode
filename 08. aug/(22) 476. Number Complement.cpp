#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int findComplement(int num) {
        long long b = 1;
        while (b < num) {
            b *= 2;
        }
        return b ^ num;
    }
};