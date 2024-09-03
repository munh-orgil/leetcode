#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int getLucky(string s, int k) {
        int sum = 0;
        for (auto c : s) {
            int x = (c - 'a' + 1);
            sum += x / 10 + x % 10;
        }
        k--;
        int ret = sum;
        while (k--) {
            sum = ret;
            ret = 0;
            while (sum) {
                ret += sum % 10;
                sum /= 10;
            }
        }
        return ret;
    }
};