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
    long long countSubarrays(vector<int>& a, int mn, int mx) {
        int n = a.size();
        int mnBound = 0, mxBound = 0;
        int mnIdx = -1, mxIdx = -1;
        long long ans = 0;

        if (mn == mx) {
            long long cnt = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] == mn) {
                    cnt++;
                }
                else {
                    ans += cnt * (cnt + 1) / 2;
                    cnt = 0;
                }
            }
            ans += cnt * (cnt + 1) / 2;
            return ans;
        }

        for (int i = 0; i < n; i++) {
            if (a[i] > mx || a[i] < mn) {
                mnBound = i + 1;
                mxBound = i + 1;
                mnIdx = -1;
                mxIdx = -1;
                continue;
            }
            if (a[i] == mn) {
                mnIdx = i;
            }
            if (a[i] == mx) {
                mxIdx = i;
            }
            if (mnIdx != -1 && mxIdx != -1) {
                int add = min(mnIdx, mxIdx) - max(mnBound, mxBound) + 1;
                for (int j = i; j < n; j++) {
                    if (a[j] < mn || a[j] > mx) {
                        break;
                    }
                    ans += add;
                }
                if (a[i] == mx) {
                    mnBound = mnIdx + 1;
                    mnIdx = -1;
                }
                else {
                    mxBound = mxIdx + 1;
                    mxIdx = -1;
                }
            }
        }
        return ans;
    }
};