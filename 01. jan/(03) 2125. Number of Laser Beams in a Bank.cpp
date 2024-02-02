#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        vector <int> sum(n, 0);
        int pt = 0;
        for (int i = 0; i < n; i++) {
            string s = bank[i];
            int cnt = 0;
            for (char c : s) {
                if (c == '1') {
                    cnt++;
                }
            }
            if (cnt) {
                sum[pt] = cnt;
                pt++;
            }
        }
        int ans = 0;
        for (int i = 1; i < pt; i++) {
            ans += sum[i - 1] * sum[i];
        }
        return ans;
    }
};

int main() {
    Solution sol = Solution{};
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int res = sol.numberOfBeams(a);
    cout << res << endl;
}
