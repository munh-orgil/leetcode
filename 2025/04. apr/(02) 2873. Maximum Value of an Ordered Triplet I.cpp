#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    long long maximumTripletValue(vector<int>& a) {
        using ll = long long;
        int n = a.size();
        long long ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    ret = max(ret, ll(a[i] - a[j]) * ll(a[k]));
                }
            }
        }
        return ret;
    }
};