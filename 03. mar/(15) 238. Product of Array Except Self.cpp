#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()

class Solution {
public:
    Solution() {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);
    }
    vector<int> productExceptSelf(vector<int>& a) {
        int n = a.size();
        vector<int> pref(n + 1, 1), suf(n + 1, 1), ret(n);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] * a[i];
            suf[n - i - 1] = suf[n - i] * a[n - i - 1];
        }
        for (int i = 0; i < n; i++) {
            ret[i] = pref[i] * suf[i + 1];
        }
        return ret;
    }
};