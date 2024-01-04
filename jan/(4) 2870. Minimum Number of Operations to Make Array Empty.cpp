#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        map<int, int> cnt;

        for (int i = 0; i < n; i++) {
            cnt[nums[i]]++;
        }

        int ans = 0;
        for (auto [key, val] : cnt) {
            if (val < 2) {
                return -1;
            }
            if (val % 3) {
                ans += val / 3 + 1;
            }
            else {
                ans += val / 3;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol = Solution{};
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int res = sol.minOperations(a);
    cout << res << endl;
}
