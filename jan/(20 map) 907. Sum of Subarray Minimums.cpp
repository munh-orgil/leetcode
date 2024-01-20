#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()

struct node {
    int l;
    int r;
    int pos;
};

class Solution {
public:
    const int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& a) {
        int n = a.size();
        map<int, node> nodes;
        for (int i = 0; i < n; i++) {
            nodes[a[i]].pos = i;
            nodes[a[i]].l = i - 1;
            nodes[a[i]].r = i + 1;
        }
        int ans = 0;
        for (auto it = nodes.rbegin(); it != nodes.rend(); it++) {
            // cout << it->first _ it->second.pos << endl;
            ans = (ans + (((it->second.pos - it->second.l) * (it->second.r - it->second.pos))
                * it->first) % MOD) % MOD;
            if (nodes[it->first].l >= 0) {
                int left = a[nodes[a[it->second.l]].pos];
                nodes[left].r = it->second.r;
            }
            if (nodes[it->first].r < n) {
                int right = a[nodes[a[it->second.r]].pos];
                nodes[right].l = it->second.l;
            }
        }
        // for (auto [key, val] : nodes) {
        //     cout << key _ val.l _ val.r << endl;
        // }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector < int > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Solution sol = Solution{};
    cout << sol.sumSubarrayMins(a) << endl;
}