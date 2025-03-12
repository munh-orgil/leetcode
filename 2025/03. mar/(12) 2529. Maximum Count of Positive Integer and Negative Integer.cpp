#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maximumCount(vector<int>& a) {
        int neg = 0, pos = 0;
        for (int i : a) {
            if (i < 0) {
                neg++;
            } else if (i > 0) {
                pos++;
            }
        }
        return max(neg, pos);
    }
};