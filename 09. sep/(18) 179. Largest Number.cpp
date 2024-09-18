#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    static bool cmp(string a, string b) {
        int n = a.size() + b.size();
        string x = a + b;
        string y = b + a;
        for (int i = 0; i < n; i++) {
            if (x[i] > y[i]) {
                return 1;
            }
            if (x[i] < y[i]) {
                return 0;
            }
        }
        return 1;
    }
    string largestNumber(vector<int>& nums) {
        int mx = 0;
        for (int num : nums) {
            mx = max(mx, num);
        }
        if (!mx) {
            return "0";
        }
        vector<string> strs;
        for (int num : nums) {
            strs.push_back(to_string(num));
        }
        sort(strs.begin(), strs.end(), cmp);
        string ret = "";
        for (string s : strs) {
            ret += s;
        }
        return ret;
    }
};