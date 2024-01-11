#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nums;
    int findPeakElement(vector<int>& nums) {
        this->nums = nums;
        pair<int, int> result = findMax(0, nums.size() - 1);
        return result.second;
    }
    pair<int, int> findMax(int l, int r) {
        if (l == r) {
            return make_pair(nums[l], l);
        }
        int mid = (l + r) / 2;
        pair<int, int> a, b;
        a = findMax(l, mid);
        b = findMax(mid + 1, r);
        if (a.first > b.first) {
            return a;
        }
        else {
            return b;
        }
    }
};

int main() {
    Solution sol = Solution{};
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << sol.findPeakElement(a) << endl;
}