#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    string longestDiverseString(int a, int b, int c) {
        using PIC = pair<int, char>;
        string ret = "";
        priority_queue < PIC > pq;
        if (a) pq.push({ a, 'a' });
        if (b) pq.push({ b, 'b' });
        if (c) pq.push({ c, 'c' });
        while (pq.size()) {
            PIC x = pq.top();
            pq.pop();
            int n = ret.size();
            if (n >= 2 && ret[n - 1] == x.second && ret[n - 2] == x.second) {
                if (!pq.size()) break;
                PIC y = pq.top();
                pq.pop();
                y.first--;
                ret += y.second;
                if (y.first) pq.push(y);
                pq.push(x);
            } else {
                x.first--;
                ret += x.second;
                if (x.first) pq.push(x);
            }
        }
        return ret;
    }
};