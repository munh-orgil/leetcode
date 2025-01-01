#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maxProfitAssignment(const vector<int>& difficulty, const vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();
        vector<pair<int, int>> job(n);
        for (int i = 0; i < n; i++) {
            job[i] = { difficulty[i], profit[i] };
        }
        sort(job.begin(), job.end());
        sort(worker.begin(), worker.end());
        set<int> st;
        int pt = 0;
        int ans = 0;
        for (int i = 0; i < m; i++) {
            while (pt < n && worker[i] >= job[pt].first) {
                st.insert(job[pt].second);
                pt++;
            }
            auto it = st.rbegin();
            ans += *it;
        }
        return ans;
    }
};