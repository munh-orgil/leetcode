#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> l(26, -1), r(26, -1);
        for (int i = 0; i < n; i++) {
            if (l[s[i] - 'a'] == -1) {
                l[s[i] - 'a'] = i;
            }
            r[s[i] - 'a'] = i;
        }
        vector<int> id(26);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int i, int j) {
            if (l[i] == l[j]) return r[i] < r[j];
            return l[i] < l[j];
            });

        int left = 0, right = 0;
        vector<int> ret;
        for (int i : id) {
            if (l[i] == -1) continue;
            if (l[i] <= right) {
                right = max(right, r[i]);
                continue;
            }
            ret.push_back(right - left + 1);
            left = l[i];
            right = r[i];
        }
        ret.push_back(right - left + 1);
        return ret;
    }
};