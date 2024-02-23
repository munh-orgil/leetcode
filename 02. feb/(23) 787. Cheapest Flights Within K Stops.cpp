#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()

#define VI vector < int >
#define VVI vector < VI >
#define VVVI vector < VVI >

class Solution {
public:
    int findCheapestPrice(int n, VVI& flights, int src, int dst, int k) {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);

        VVVI paths(n, VVI());
        int m = flights.size();
        for (auto f : flights) {
            paths[f[0]].push_back({ f[1], f[2] });
        }
        VI minAfterMv(n, 1e9);
        priority_queue < tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq;
        minAfterMv[src] = 0;
        pq.push({ 0, 0, src });
        while (!pq.empty()) {
            auto [mv, cst, from] = pq.top();
            pq.pop();
            int to, price;
            for (auto path : paths[from]) {
                to = path[0];
                price = path[1];
                if (mv <= k && cst + price < minAfterMv[to]) {
                    minAfterMv[to] = cst + price;
                    pq.push({ mv + 1, cst + price, to });
                }
            }
        }
        return minAfterMv[dst] == 1e9 ? -1 : minAfterMv[dst];
    }
};

int main() {
    int n, m, src, dst, k;
    cin >> n >> m;
    vector<vector<int>> flights(m, vector<int> (3));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> flights[i][j];
        }
    }
    cin >> src >> dst >> k;
    Solution sol = Solution{};
    int res = sol.findCheapestPrice(n, flights, src, dst, k);
    debug(res);
}