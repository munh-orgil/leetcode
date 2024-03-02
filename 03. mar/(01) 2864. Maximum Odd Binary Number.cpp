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
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int cnt = 0;
        string ret = "";
        for (auto ch : s) {
            if (ch == '1') {
                cnt++;
            }
        }
        for (int i = 1; i < cnt; i++) {
            ret += "1";
        }
        for (int i = cnt; i < n; i++) {
            ret += "0";
        }
        ret += "1";
        return ret;
    }
};

int main() {
    string s;
    cin >> s;
    auto sol = Solution{};
    auto res = sol.maximumOddBinaryNumber(s);
    cout << res << endl;
}
