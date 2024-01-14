#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()
#define ll long long

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        if (word1.size() != word2.size()) {
            return false;
        }
        int n = word1.size();
        vector < ll > cnt1(26, 0), cnt2(26, 0);
        for (int i = 0; i < n; i++) {
            cnt1[word1[i] - 'a']++;
            cnt2[word2[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt1[i] * cnt2[i] == 0 && cnt1[i] + cnt2[i] != 0) {
                return false;
            }
        }
        sort(ALL(cnt1));
        sort(ALL(cnt2));
        for (int i = 0; i < 26; i++) {
            if (cnt1[i] != cnt2[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s, t;
    cin >> s >> t;
    Solution sol = Solution{};
    if (sol.closeStrings(s, t)) {
        cout << "true\n";
    }
    else {
        cout << "false\n";
    }
}