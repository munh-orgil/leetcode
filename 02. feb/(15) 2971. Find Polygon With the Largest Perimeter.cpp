#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);

        sort(nums.begin(), nums.end());
        int n = nums.size(), cnt = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        for (int i = n - 1; i >= 2; i--) {
            if (sum - nums[i] > nums[i]) {
                return sum;
            }
            sum -= nums[i];
        }
        return -1;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Solution sol = Solution{};
    auto res = sol.largestPerimeter(a);
    cout << res << endl;
}