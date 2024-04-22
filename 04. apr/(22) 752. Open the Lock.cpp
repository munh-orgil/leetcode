#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    string toString(int x) {
        string ret = "0000";
        for (int i = 0; i < 4; i++) {
            ret[4 - i] = (x % 10) + '0';
            x /= 10;
        }
        return ret;
    }
    int openLock(vector<string>& deadends, string target) {
        queue<pair<int, string>> pq;
        unordered_map<string, bool> vis;
        for (string d : deadends) {
            vis[d] = 1;
        }
        if (vis["0000"]) {
            return -1;
        }
        pq.push({ 0, "0000" });
        while (!pq.empty()) {
            auto [d, s] = pq.front();
            pq.pop();
            if (s == target) {
                return d;
            }
            for (int i = 0; i < 4; i++) {
                string next = s;
                next[i] = (s[i] - '0' + 1) % 10 + '0';
                string prev = s;
                prev[i] = (s[i] - '0' + 9) % 10 + '0';
                if (!vis[next]) {
                    vis[next] = 1;
                    pq.push({ d + 1, next });
                }
                if (!vis[prev]) {
                    vis[prev] = 1;
                    pq.push({ d + 1, prev });
                }
            }
        }
        return -1;
    }
};
