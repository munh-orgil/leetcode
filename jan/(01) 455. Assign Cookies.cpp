#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int pt = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= g[pt]) {
                ans++;
                pt++;
            }
            if (pt >= g.size()) {
                break;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol = Solution{};
    int n, m;
    cin >> n >> m;
    vector<int> greeds(n), cookies(m);
    for (int i = 0; i < n; i++) {
        cin >> greeds[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> cookies[i];
    }
    cout << sol.findContentChildren(greeds, cookies) << endl;
}