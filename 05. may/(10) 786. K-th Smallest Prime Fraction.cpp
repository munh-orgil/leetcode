#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<pair<int, int>> p;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                p.push_back({ arr[i], arr[j] });
            }
        }

        sort(p.begin(), p.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.first * b.second < a.second * b.first;
            });

        return { p[k - 1].first, p[k - 1].second };
    }
};