#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    struct node {
        int par, val;
        node() {}
        node(int p, int v) {
            par = p;
            val = v;
        }
    };
    vector<node> dsu;
    int find(int i) {
        if (dsu[i].par == i) {
            return i;
        }
        return dsu[i].par = find(dsu[i].par);
    }
    void join(int i, int j, int w) {
        int x = find(i);
        int y = find(j);
        dsu[y].par = x;
        if (dsu[x].val != -1) {
            w &= dsu[x].val;
        }
        if (dsu[y].val != -1) {
            w &= dsu[y].val;
        }
        dsu[x].val = w;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> ret;
        dsu.resize(n);
        for (int i = 0; i < n; i++) {
            dsu[i] = node(i, -1);
        }
        for (vector<int>& e : edges) {
            join(e[0], e[1], e[2]);
        }
        for (vector<int>& q : query) {
            int x = find(q[0]);
            int y = find(q[1]);
            if (x != y) {
                ret.push_back(-1);
                continue;
            }
            ret.push_back(dsu[x].val);
        }
        return ret;
    }
};