#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    string minRemoveToMakeValid(string s) {
        int cnt = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                cnt++;
            }
            else if (s[i] == ')') {
                if (cnt == 0) {
                    s[i] = '*';
                }
                else {
                    cnt--;
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (cnt > 0 && s[i] == '(') {
                s[i] = '*';
                cnt--;
            }
        }
        string result = "";
        for (char c : s) {
            if (c != '*')
                result += c;
        }
        return result;
    }
};