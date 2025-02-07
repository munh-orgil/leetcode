#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> queryResults(int n, vector<vector<int>>& queries) {
        unordered_map<int, int> cnt, c;
        vector<int> ret;
        for (vector<int>& q : queries) {
            if (c[q[0]]) {
                cnt[c[q[0]]]--;
                if (cnt[c[q[0]]] <= 0) {
                    cnt.erase(c[q[0]]);
                }
            }
            cnt[q[1]]++;
            c[q[0]] = q[1];
            ret.push_back(cnt.size());
        }
        return ret;
    }
};