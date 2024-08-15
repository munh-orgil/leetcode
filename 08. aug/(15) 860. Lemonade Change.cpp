#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool lemonadeChange(vector<int>& bills) {
        int a = 0, b = 0, c = 0;
        int n = bills.size();
        for (int i = 0; i < n; i++) {
            switch (bills[i]) {
            case 5:
                a++;
                break;
            case 10:
                if (a == 0) {
                    return false;
                }
                a--;
                b++;
                break;
            case 20:
                if (a && b) {
                    a--;
                    b--;
                    c++;
                    break;
                }
                if (a >= 3) {
                    a -= 3;
                    c++;
                    break;
                }
                return false;
                break;
            }
        }
        return true;
    }
};