#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        for (int x = 1 << 30; x >= 1; x /= 2) {
            if (x > left && x > right) {
                continue;
            }
            int a = left & x;
            int b = right & x;
            if (a == b) {
                ans += a;
            }
            else {
                return ans;
            }
        }
        return left & right;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Solution sol = Solution{};
    auto res = sol.rangeBitwiseAnd(n, m);
    cout << res << endl;
}