#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()

struct Job {
    int start;
    int end;
    int profit;
};

bool cmp(Job a, Job b) {
    return a.end < b.end;
}

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector < Job > jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i].start = startTime[i];
            jobs[i].end = endTime[i];
            jobs[i].profit = profit[i];
        }
        sort(ALL(jobs), cmp);
        unordered_map < int, int > dp;
        vector < int > ends(1, 0);
        dp[0] = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int lb = upper_bound(ALL(ends), jobs[i].start) - ends.begin() - 1;
            dp[jobs[i].end] = max(dp[ends[lb]] + jobs[i].profit, dp[ends[ends.size() - 1]]);
            ends.push_back(jobs[i].end);
            ans = max(ans, dp[jobs[i].end]);
        }
        // for (auto [key, val] : dp) {
        //     cout << key _ val << endl;
        // }
        return ans;
    }
};

int main() {
    Solution sol = Solution{};
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    int res = sol.jobScheduling(a, b, c);
    cout << res << endl;
}