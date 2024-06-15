#include<bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int>& x, pair<int, int>& y) {
    if (x.first == y.first) {
        return x.second > y.second;
    }
    return x.first < y.first;
}

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        multiset<int, greater<int>> a;
        multiset<pair<int, int>> b;

        for (int i = 0; i < n; i++) {
            if (capital[i] <= w) {
                a.insert(profits[i]);
            } else {
                b.insert({ capital[i], profits[i] });
            }
        }
        int cnt = 0;
        pair<int, int> st;
        while (k && cnt < n) {
            if (b.empty()) {
                w += *(a.begin());
                a.erase(a.begin());
            } else {
                st = *(b.begin());
                if (st.first > w) {
                    if (a.empty()) {
                        return w;
                    }
                    w += *(a.begin());
                    a.erase(a.begin());
                } else {
                    a.insert(st.second);
                    b.erase(b.begin());
                    continue;
                }
            }
            cnt++;
            k--;
        }

        return w;
    }
};