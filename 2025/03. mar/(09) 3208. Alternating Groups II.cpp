#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int numberOfAlternatingGroups(vector<int>& a, int k) {
        int n = a.size();
        int cnt = 0;
        for (int i = 0; i < k - 1; i++) {
            if (a[i] == a[i + 1]) {
                cnt++;
            }
        }
        int ret = (cnt == 0);
        for (int i = 1; i < n; i++) {
            cnt -= (a[i] == a[i - 1]);
            cnt += (a[(i + k - 1) % n] == a[(i + k - 2) % n]);
            ret += (cnt == 0);
        }
        return ret;
    }
};