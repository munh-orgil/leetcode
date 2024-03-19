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
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for (char ch : tasks) {
            cnt[ch - 'A']++;
        }
        int mx = 0;
        int x = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > mx) {
                mx = cnt[i];
                x = 1;
            }
            else if (cnt[i] == mx) {
                x++;
            }
        }
        int ret = tasks.size();
        ret = max(ret, (n + 1) * (mx - 1) + x);
        return ret;
    }
};