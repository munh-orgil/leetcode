#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);

        int n = strs.size();
        unordered_map<string, vector<string>> cnt;
        string s;
        for (int i = 0; i < n; i++) {
            s = strs[i];
            sort(ALL(s));
            cnt[s].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for (auto [k, v] : cnt) {
            res.push_back(v);
        }
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto sol = Solution{};
    auto res = sol.groupAnagrams(a);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}