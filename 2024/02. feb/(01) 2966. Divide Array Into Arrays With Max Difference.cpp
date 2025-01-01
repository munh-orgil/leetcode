#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);

        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ret(n / 3), empty;
        vector<int> tmp(3);
        for (int i = 0; i < n / 3; i++) {
            tmp = { nums[i * 3], nums[i * 3 + 1], nums[i * 3 + 2] };
            if (tmp[2] - tmp[0] > k) {
                return empty;
            }
            ret[i] = tmp;
        }
        return ret;
    }
};

int main() {
    int n, k;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> k;
    auto sol = Solution{};
    auto res = sol.divideArray(a, k);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}