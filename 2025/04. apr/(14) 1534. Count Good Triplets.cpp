#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(arr[i] - arr[j]) > a) continue;
                for (int k = j + 1; k < n; k++) {
                    ret += (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c);
                }
            }
        }
        return ret;
    }
};