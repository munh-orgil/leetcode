#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        using PII = pair<int, int>;
        int n = times.size();
        for (int i = 0; i < n; i++) {
            times[i].push_back(i);
        }
        sort(times.begin(), times.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        priority_queue<PII, vector<PII>, greater<PII>> taken;
        for (int i = 0; i < n; i++) {
            pq.push(i);
        }
        vector<int> ret(n);
        for (int i = 0; i < n; i++) {
            while (taken.size() && taken.top().first < times[i][0]) {
                pq.push(taken.top().second);
                taken.pop();
            }
            ret[times[i][2]] = pq.top();
            taken.push({ times[i][1], pq.top() });
            pq.pop();
        }
        return ret[targetFriend];
    }
};
