#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    long long minimumCost(string s, string t, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = s.size();
        vector<vector<long long>> dist(26, vector<long long> (26, 1e12));
        for (int i = 0; i < 26; i++) {
            dist[i][i] = 0;
        }
        int m = original.size();
        for (int i = 0; i < m; i++) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            dist[from][to] = min(dist[from][to], (long long)(cost[i]));
        }
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        long long ret = 0;
        for (int i = 0; i < n; i++) {
            int from = s[i] - 'a';
            int to = t[i] - 'a';
            if (dist[from][to] >= 1e12) {
                return -1;
            }
            ret += dist[from][to];
        }
        return ret;
    }
};