#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int nthUglyNumber(int n) {
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, bool> incl;
        pq.push(1);
        incl[1] = 1;
        int x;
        while (--n) {
            x = pq.top();
            pq.pop();
            if (!incl[x * 2]) {
                pq.push(x * 2);
                incl[x * 2] = 1;
            }
            if (!incl[x * 3]) {
                pq.push(x * 3);
                incl[x * 3] = 1;
            }
            if (!incl[x * 5]) {
                pq.push(x * 5);
                incl[x * 5] = 1;
            }
        }
        return pq.top();
    }
};