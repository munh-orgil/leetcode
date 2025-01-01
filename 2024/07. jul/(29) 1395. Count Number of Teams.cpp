#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int solve(vector<int>& a) {
        int n = a.size();
        int ret = 0;
        int l, r;
        for (int i = 1; i < n - 1; i++) {
            l = 0;
            r = 0;
            for (int j = 0; j < i; j++) {
                if (a[j] < a[i]) {
                    l++;
                }
            }
            for (int j = i + 1; j < n; j++) {
                if (a[j] > a[i]) {
                    r++;
                }
            }
            ret += l * r;
        }
        return ret;
    }
    int numTeams(vector<int>& a) {
        int ret = solve(a);
        reverse(a.begin(), a.end());
        ret += solve(a);
        return ret;
    }
};