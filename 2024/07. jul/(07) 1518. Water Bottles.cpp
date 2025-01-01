#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int numWaterBottles(int numBottles, int numExchange) {
        int ret = numBottles;
        while (numBottles / numExchange) {
            ret += numBottles / numExchange;
            numBottles = numBottles / numExchange + numBottles % numExchange;
        }
        return ret;
    }
};