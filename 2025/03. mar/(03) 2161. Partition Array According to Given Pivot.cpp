#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> pivotArray(vector<int>& a, int x) {
        vector<int> ret, b, c;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (a[i] < x) {
                ret.push_back(a[i]);
            } else if (a[i] == x) {
                b.push_back(a[i]);
            } else {
                c.push_back(a[i]);
            }
        }
        for (int i : b) {
            ret.push_back(i);
        }
        for (int i : c) {
            ret.push_back(i);
        }
        return ret;
    }
};