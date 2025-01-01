#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int countSeniors(vector<string>& details) {
        int n = details.size();
        int ret = 0;
        for (string detail : details) {
            int age = (detail[11] - '0') * 10 + detail[12] - '0';
            ret += (age > 60);
        }
        return ret;
    }
};