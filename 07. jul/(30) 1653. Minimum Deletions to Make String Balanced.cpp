#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minimumDeletions(string s) {
        int n = s.size();
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') {
                idx = i;
                break;
            }
        }
        if (idx == -1) {
            return 0;
        }
        int cnt = 0;
        for (int i = idx + 1; i < n; i++) {
            cnt += (s[i] == 'a');
        }
        int prev = 0;
        int ret = 1e9;
        for (int i = idx; i < n; i++) {
            if (s[i] == 'b') {
                ret = min(ret, cnt + prev);
                prev++;
            }
            else {
                cnt--;
            }
        }
        ret = min(ret, prev);
        return ret;
    }
};