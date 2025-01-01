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
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        if (!n) {
            return 0;
        }
        sort(tokens.begin(), tokens.end());
        int pt1 = 0, pt2 = n - 1;
        int score = 0, ret = 0;
        if (power < tokens[0]) {
            return 0;
        }
        while (pt1 <= pt2) {
            if (power >= tokens[pt1]) {
                score++;
                power -= tokens[pt1];
                pt1++;
                ret = max(ret, score);
            }
            else {
                if (score > 0) {
                    power += tokens[pt2];
                    score--;
                    pt2--;
                }
                else {
                    return ret;
                }
            }
        }
        return ret;
    }
};

int main() {
    int n, p;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> p;
    Solution sol = Solution{};
    auto res = sol.bagOfTokensScore(a, p);
    cout << res << endl;
}