#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define LLA(a) a.rbegin(), a.rend()
#define ALL(a) a.begin(), a.end()

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);

        int m = meetings.size();
        vector<long long> rooms(n, 0);
        vector<int> cnt(n, 0);
        sort(meetings.begin(), meetings.end());
        for (auto meet : meetings) {
            long long mnEnd = INFINITY;
            int mnIdx = 0;
            bool found = false;
            for (int j = 0; j < n; j++) {
                if (rooms[j] < mnEnd) {
                    mnEnd = rooms[j];
                    mnIdx = j;
                }
                if (rooms[j] <= meet[0]) {
                    rooms[j] = meet[1];
                    cnt[j]++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                rooms[mnIdx] += meet[1] - meet[0];
                cnt[mnIdx]++;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << cnt[i] << " ";
        }
        cout << endl;
        int mx = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (cnt[i] > mx) {
                mx = cnt[i];
                ans = i;
            }
        }
        return ans;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int> (2));
    for (int i = 0; i < m; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    Solution sol = Solution{};
    auto res = sol.mostBooked(n, a);
    cout << res << endl;
}
