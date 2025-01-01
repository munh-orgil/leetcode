#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    string repeatLimitedString(string s, int r) {
        int n = s.size();
        vector<int> cnt(26, 0);
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i]) pq.push(i);
        }
        string ret = "";
        int l;
        while (pq.size()) {
            int x = pq.top();
            pq.pop();
            if (ret.size() && ret.back() == 'a' + x) {
                if (pq.empty()) {
                    break;
                }
                int y = pq.top();
                pq.pop();
                pq.push(x);
                ret += char('a' + y);
                cnt[y]--;
                if (cnt[y]) pq.push(y);
            } else {
                l = min(cnt[x], r);
                cnt[x] -= l;
                for (int i = 0; i < l; i++) {
                    ret += char('a' + x);
                }
                if (cnt[x]) pq.push(x);
            }
        }
        return ret;
    }
};