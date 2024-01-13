#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()
#define ll long long

class Solution {
public:
    int minSteps(string s, string t) {
        int cnt[26] = {};
        int n = s.size();
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
        }
        for (int i = 0; i < n; i++) {
            int k = t[i] - 'a';
            if (cnt[k]) {
                cnt[k]--;
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += cnt[i];
        }
        return ans;
    }
};

int main() {
    string s, t;
    cin >> s >> t;
    Solution sol = Solution{};
    cout << sol.minSteps(s, t) << endl;
}