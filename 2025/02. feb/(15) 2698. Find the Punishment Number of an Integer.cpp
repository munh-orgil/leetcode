#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool rec(string& s, int idx, int sum, int goal) {
        if (sum > goal) {
            return 0;
        }
        int n = s.size();
        if (idx == n) {
            return sum == goal;
        }
        for (int i = 1; i <= n - idx; i++) {
            int x = stoi(s.substr(idx, i));
            if (rec(s, idx + i, sum + x, goal)) {
                return true;
            }
        }
        return false;
    }
    int punishmentNumber(int n) {
        int ret = 0;
        for (int i = 1; i <= n; i++) {
            string s = to_string(i * i);
            if (rec(s, 0, 0, i)) {
                ret += i * i;
            }
        }
        return ret;
    }
};