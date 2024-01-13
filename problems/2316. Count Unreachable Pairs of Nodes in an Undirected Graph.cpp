#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> parent;
    void init(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {

    }
};

int main() {
    int n, m, u, v;
    cin >> n, m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        edges.push_back({ u, v });
    }
    Solution sol = Solution{};
    cout << sol.countPairs(n, edges) << endl;
}