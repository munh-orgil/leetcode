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
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n + 1, 0);
        for (int num : nums) {
            if (vis[num]) {
                return num;
            }
            vis[num] = true;
        }
        return 0;
    }
};