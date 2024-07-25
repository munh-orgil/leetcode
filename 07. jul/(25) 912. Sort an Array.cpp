#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    void mergeSort(int l, int r, vector<int>& arr) {
        if (l == r) {
            return;
        }
        int m = (l + r) / 2;
        mergeSort(l, m, arr);
        mergeSort(m + 1, r, arr);
        vector<int> tmp(r - l + 1);
        int pt1 = l, pt2 = m + 1, idx = 0;
        while (pt1 <= m && pt2 <= r) {
            if (arr[pt1] < arr[pt2]) {
                tmp[idx] = arr[pt1];
                pt1++;
                idx++;
            }
            else {
                tmp[idx] = arr[pt2];
                pt2++;
                idx++;
            }
        }
        while (pt1 <= m) {
            tmp[idx] = arr[pt1];
            pt1++;
            idx++;
        }
        while (pt2 <= r) {
            tmp[idx] = arr[pt2];
            pt2++;
            idx++;
        }
        for (int i = l; i <= r; i++) {
            arr[i] = tmp[i - l];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(0, n - 1, nums);
        return nums;
    }
};