#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 

struct S {
    int start;
    int end;
    int profit;
};

bool cmp(S x, S y) {
    return x.start < y.start;
}

class Solution {
public:
    vector < vector < int > > path;
    vector < int > st;
    vector < int > et;
    vector < int > prof;
    int ans = 0;
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector < S > arr(n);
        for (int i = 0; i < n; i++) {
            arr[i].start = startTime[i];
            arr[i].end = endTime[i];
            arr[i].profit = profit[i];
        }
        sort(arr.begin(), arr.end(), cmp);
        for (int i = 0; i < n; i++) {
            startTime[i] = arr[i].start;
            endTime[i] = arr[i].end;
            profit[i] = arr[i].profit;
        }
        st = startTime;
        et = endTime;
        prof = profit;
        path.resize(n + 1);
        ans = 0;
        int idx = 0, mnEnd = endTime[0];
        while (idx < n && startTime[idx] < mnEnd) {
            path[0].push_back(idx);
            idx++;
            mnEnd = min(mnEnd, endTime[idx]);
        }
        buildDFS(0);
        for (auto to : path[0]) {
            sumDFS(to + 1, prof[to]);
        }
        return ans;
    }
    void appendChild(int par) {
        auto lb = lower_bound(st.begin(), st.end(), et[par]);
        if (lb == st.end()) {
            return;
        }
        int idx = lb - st.begin();
        int mnEnd = et[idx];
        while (idx < st.size() && st[idx] < mnEnd) {
            path[par + 1].push_back(idx);
            idx++;
            if (idx < et.size()) {
                mnEnd = min(mnEnd, et[idx]);
            }
        }
    }
    void buildDFS(int cur) {
        for (int to : path[cur]) {
            appendChild(to);
            buildDFS(to + 1);
        }
    }
    void sumDFS(int cur, int sum) {
        ans = max(ans, sum);
        for (auto to : path[cur]) {
            sumDFS(to + 1, sum + prof[to]);
        }
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