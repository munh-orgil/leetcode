#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int shortestSubarray(vector<int>& a, int k) {
        int n = a.size();
        int ret = 1e9;
        vector<long long> pre(n + 1, 0);
        deque<int> q;
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + a[i];
        }
        for (int i = 0; i < n; i++) {
            if (pre[i + 1] >= k || (q.size() && pre[i + 1] - pre[q.front()] >= k)) {
                int x = 0;
                while (q.size() && pre[i + 1] - pre[q.front()] >= k) {
                    x = q.front();
                    q.pop_front();
                }
                ret = min(ret, i - x + 1);
            }
            while (q.size() && pre[q.back()] >= pre[i + 1]) {
                q.pop_back();
            }
            q.push_back(i + 1);
        }
        return (ret == 1e9 ? -1 : ret);
    }
};