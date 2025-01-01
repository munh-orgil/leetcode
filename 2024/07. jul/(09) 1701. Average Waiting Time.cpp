#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        int st = 0, end;
        double sum = 0;
        for (int i = 0; i < n; i++) {
            end = max(customers[i][0], st) + customers[i][1];
            sum += end - customers[i][0];
            st = end;
        }
        double ret = sum / n;
        return ret;
    }
};