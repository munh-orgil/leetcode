#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    struct dsu {
        int par;
        long long size;
    };
    vector < dsu > nodes;
    void init(int n) {
        nodes.resize(n);
        for (int i = 0; i < n; i++) {
            dsu cur;
            cur.size = 1LL;
            cur.par = i;
            nodes[i] = cur;
        }
    }
    int Head(int x) {
        if (nodes[x].par == x) {
            return x;
        }
        return nodes[x].par = Head(nodes[x].par);
    }
    void Union(int x, int y) {
        x = Head(x);
        y = Head(y);
        if (x == y) {
            return;
        }
        nodes[x].par = y;
        nodes[y].size += nodes[x].size;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        init(n);
        int m = edges.size();
        for (int i = 0; i < m; i++) {
            Union(edges[i][0], edges[i][1]);
        }
        long long ans = 0;
        int k = n;
        for (int i = 0; i < n; i++) {
            dsu node = nodes[i];
            if (nodes[i].par == i) {
                ans += node.size * (k - node.size);
                k -= node.size;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol = Solution{};
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector < int > (2));
    for (int i = 0; i < m; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    cout << sol.countPairs(n, a) << endl;
}