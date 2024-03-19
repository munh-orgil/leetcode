#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()

class Solution {
public:
    vector<int> nums = { 12, 23, 34, 45, 56, 67, 78, 89, 123, 234, 345, 456, 567, 678, 789, 1234, 2345, 3456, 4567, 5678, 6789, 12345, 23456, 34567, 45678, 56789, 123456, 234567, 345678, 456789, 1234567, 2345678, 3456789, 12345678, 23456789, 123456789 };
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= low && nums[i] <= high) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

int main() {
    int n, k;
    cin >> n;
    cin >> k;
    auto sol = Solution{};
    auto res = sol.sequentialDigits(n, k);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}
