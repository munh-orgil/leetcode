#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool checkValidString(string s) {
        int cnt = 0;
        int star = 0;
        int last = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            switch (s[i]) {
            case '(':
                cnt++;
                break;
            case ')':
                cnt--;
                if (cnt < 0) {
                    if (star > 0) {
                        star--;
                        cnt++;
                    }
                    else {
                        return false;
                    }
                }
                break;
            case '*':
                star++;
                last = cnt;
                break;
            default:
                break;
            }
        }
        int dif = cnt - last;
        if (dif < 0) {
            star += dif;
            cnt += dif;
        }
        if (cnt > last || cnt > star) {
            return false;
        }
        return true;
    }
};
