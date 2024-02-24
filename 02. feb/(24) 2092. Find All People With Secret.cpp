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
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);

        int m = meetings.size();
        for (int i = 0; i < m; i++) {
            int x = meetings[i][0];
            int y = meetings[i][1];
            meetings[i][0] = min(x, y);
            meetings[i][1] = max(x, y);
        }
        sort(meetings.begin(), meetings.end(), [](vector<int> &a, vector<int> &b) {
            if (a[2] == b[2]) {
                return a[0] < b[0];
            }
            return a[2] < b[2];
            });

        init(n);
        know[0] = know[firstPerson] = true;
        set<int> tmp;
        for (int i = 0; i < m; i++) {
            if (i > 0 && meetings[i][2] != meetings[i - 1][2]) {
                for (auto elem : tmp) {
                    if (know[adj[elem]]) {
                        know[elem] = true;
                    }
                    adj[elem] = elem;
                }
                tmp.clear();
            }
            tmp.insert(meetings[i][0]);
            tmp.insert(meetings[i][1]);
            merge(meetings[i][0], meetings[i][1]);
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (know[i] || know[adj[i]]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
    vector<int> adj;
    vector<bool> know;
    void init(int n) {
        adj.resize(n);
        know.resize(n);
        for (int i = 0; i < n; i++) {
            adj[i] = i;
            know[i] = 0;
        }
    }
    int find(int x) {
        if (adj[x] != x) {
            return adj[x] = find(adj[x]);
        }
        return x;
    }
    void merge(int x, int y) {
        int a = find(x);
        int b = find(y);
        adj[b] = a;
        bool shared = know[a] || know[b];
        know[a] = know[b] = know[x] = know[y] = shared;
    }
};

int main() {
    int n, m, k;
    cin >> n >> m;
    vector<vector<int>> meetings(m, vector<int> (3));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> meetings[i][j];
        }
    }
    cin >> k;
    Solution sol = Solution{};
    vector<int> res = sol.findAllPeople(n, meetings, k);
    for (auto elem : res) {
        cout << elem << " ";
    }
    cout << endl;
}