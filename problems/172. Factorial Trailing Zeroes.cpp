#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int k = 5;
        int ans = 0;
        while (k <= n) {
            ans += n / k;
            k *= 5;
        }
        return ans;
    }
};

int main() {
    Solution sol = Solution{};
    int n, m;
    cin >> n;
    cout << sol.trailingZeroes(n) << endl;
}