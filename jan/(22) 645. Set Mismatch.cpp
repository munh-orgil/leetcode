#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);
        int n = nums.size();
        const int N = 1e4 + 5;
        vector<int> cnt(N, 0);
        int num1 = 0;
        int dif = n * (n + 1) / 2;
        for (int i = 0; i < n; i++) {
            cnt[nums[i]]++;
            if (cnt[nums[i]] > 1) {
                num1 = nums[i];
            }
            dif -= nums[i];
        }
        return { num1, num1 + dif };
    }
};

int main() {
    int n;
    cin >> n;
    vector < int > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Solution sol = Solution{};
    auto res = sol.findErrorNums(a);
    cout << res[0] _ res[1] << endl;
}