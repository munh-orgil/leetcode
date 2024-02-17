#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);

        int n = heights.size();
        priority_queue<int> l;
        int mn = heights[0], mx = heights[0];
        for (int i = 1; i < n; i++) {
            int dif = heights[i] - heights[i - 1];
            if (dif <= 0) {
                continue;
            }
            l.push(dif);
            bricks -= dif;
            while (bricks < 0) {
                bricks += l.top();
                l.pop();
                ladders--;
            }
            if (ladders < 0) {
                return i - 1;
            }
        }
        return n - 1;
    }
};

int main() {
    int n, m, k;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m >> k;
    Solution sol = Solution{};
    auto res = sol.furthestBuilding(a, m, k);
    cout << res << endl;
}