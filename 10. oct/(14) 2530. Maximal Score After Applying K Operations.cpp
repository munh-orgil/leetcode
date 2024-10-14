#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq;
        for (int i : nums) {
            pq.push(i);
        }
        long long ret = 0;
        while (--k) {
            int x = pq.top();
            pq.pop();
            ret += x;
            pq.push((x + 2) / 3);
        }
        return ret;
    }
};
