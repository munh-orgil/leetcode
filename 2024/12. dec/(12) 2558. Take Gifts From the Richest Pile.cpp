#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    long long pickGifts(vector<int>& a, int k) {
        priority_queue<int> pq;
        for (int i : a) {
            pq.push(i);
        }
        for (int i = 0; i < k; i++) {
            int x = pq.top();
            pq.pop();
            pq.push(sqrt(x));
        }
        long long ret = 0;
        while (pq.size()) {
            ret += pq.top();
            pq.pop();
        }
        return ret;
    }
};