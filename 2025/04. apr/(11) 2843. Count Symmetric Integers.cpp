#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    int countSymmetricIntegers(int low, int high) {
        int ret = 0;
        vector<int> a;
        for (int i = low; i <= high; i++) {
            a.clear();
            int x = i;
            while (x) {
                a.push_back(x % 10);
                x /= 10;
            }
            if (a.size() % 2) continue;
            x = 0;
            int y = 0;
            for (int j = 0; j < a.size() / 2; j++) {
                x += a[j];
            }
            for (int j = a.size() / 2; j < a.size(); j++) {
                y += a[j];
            }
            ret += (x == y);
        }
        return ret;
    }
};