#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);

        int n = nums.size();
        vector<int> ret(n, 0);
        int pos = 0, neg = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                ret[neg] = nums[i];
                neg += 2;
            }
            else {
                ret[pos] = nums[i];
                pos += 2;
            }
        }
        return ret;
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
    auto res = sol.rearrangeArray(a);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}