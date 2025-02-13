#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minOperations(vector<int>& a, int k) {
        using ll = long long;
        int n = a.size();
        priority_queue<ll, vector<ll>, greater<ll>> pq(a.begin(), a.end());
        int ret = 0;
        while (pq.size() >= 2) {
            ll x = pq.top();
            pq.pop();
            ll y = pq.top();
            pq.pop();
            if (x >= k) {
                break;
            }
            ret++;
            pq.push(x * 2 + y);
        }
        return ret;
    }
};