#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minOperations(vector<string>& logs) {
        int ret = 0;
        for (string l : logs) {
            if (l[0] == '.') {
                if (l[1] == '.') {
                    ret = max(ret - 1, 0);
                }
            } else {
                ret++;
            }
        }
        return ret;
    }
};