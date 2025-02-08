#include<bits/stdc++.h>

using namespace std;

class NumberContainers {
public:
    unordered_map<int, int> val;
    unordered_map<int, set<int>> mp;
    NumberContainers() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        val = unordered_map<int, int>();
        mp = unordered_map<int, set<int>>();
    }

    void change(int idx, int x) {
        mp[val[idx]].erase(idx);
        mp[x].insert(idx);
        val[idx] = x;
    }
    int find(int x) {
        if (mp[x].size()) {
            return *mp[x].begin();
        } else {
            return -1;
        }
    }
};