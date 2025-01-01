#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()

class Solution {
public:
    Solution() {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);
    }
    int minimumLength(const string& s) {
        int n = s.size();
        int pt1 = 0, pt2 = n - 1;
        char ch;
        while (pt1 < pt2 && s[pt1] == s[pt2]) {
            ch = s[pt1];
            while (pt1 < n && s[pt1] == ch) {
                pt1++;
            }
            while (pt1 < pt2 && s[pt2] == ch) {
                pt2--;
            }
        }
        return pt2 - pt1 + 1;
    }
};

int main() {
    string s;
    cin >> s;
    Solution sol = Solution{};
    auto res = sol.minimumLength(s);
    cout << res << endl;
}