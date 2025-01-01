#include<bits/stdc++.h>

using namespace std;

class KthLargest {
public:
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int limit;
    KthLargest(int k, std::vector<int>& nums) : limit(k) {
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        if (pq.size() < limit) {
            pq.push(val);
        } else if (val > pq.top()) {
            pq.pop();
            pq.push(val);
        }

        return pq.empty() ? 0 : pq.top();
    }
};