#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()

class Solution {
public:
    int maxLength(vector<string>& arr) {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);
        int n = arr.size();
        int bm = 1 << n;
        vector < int > cnt(26, 0);
        int ans = 0, cur = 0;
        for (int i = 0; i < bm; i++) {
            for (int j = 0; j < n; j++) {
                int x = 1 << j;
                if (x & i) {
                    for (auto ch : arr[j]) {
                        cnt[ch - 'a']++;
                    }
                }
            }
            cur = 0;
            for (auto c : cnt) {
                if (c > 1) {
                    cur = 0;
                    break;
                }
                cur += c;
            }
            ans = max(ans, cur);
            for (int j = 0; j < 26; j++) {
                cnt[j] = 0;
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector < string > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Solution sol = Solution{};
    auto res = sol.maxLength(a);
    cout << res << endl;
}