#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    string toString(int num) {
        switch (num) {
        case 1:
            return "Gold Medal";
        case 2:
            return "Silver Medal";
        case 3:
            return "Bronze Medal";
        }
        string ret = "";
        while (num) {
            ret += char((num % 10) + '0');
            num /= 10;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> p(n);
        for (int i = 0; i < n; i++) {
            p[i].first = score[i];
            p[i].second = i;
        }
        sort(p.rbegin(), p.rend());
        vector<string> ret(n);
        for (int i = 0; i < n; i++) {
            ret[p[i].second] = toString(i + 1);
        }
        return ret;
    }
};