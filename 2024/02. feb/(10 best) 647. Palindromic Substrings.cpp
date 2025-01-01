#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()

class Solution {
public:
    int palin(int i, int j, string &s) {
        int cnt = 0;
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            cnt++;
            i--;
            j++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int cnt = 0;
        for (int i = 0; i < s.length();i++) {
            int j = i;
            int odds = palin(i, j, s);
            int evens = palin(i, j + 1, s);
            cnt += (odds + evens);
        }
        return cnt;

    }
};

int main() {
    string s;
    cin >> s;
    Solution sol = Solution{};
    int res = sol.countSubstrings(s);
    cout << res << endl;
}