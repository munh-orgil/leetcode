#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maximumSwap(int num) {
        vector<int> a, b;
        int x = num;
        while (x) {
            a.push_back(x % 10);
            x /= 10;
        }
        reverse(a.begin(), a.end());
        int n = a.size();
        int ret = num;
        b = a;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                swap(b[i], b[j]);
                int tmp = 0;
                for (int k = 0; k < n; k++) {
                    tmp = tmp * 10 + b[k];
                }
                ret = max(ret, tmp);
                b = a;
            }
        }
        return ret;
    }
};