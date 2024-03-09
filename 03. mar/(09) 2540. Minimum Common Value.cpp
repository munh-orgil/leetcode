#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()

class Solution {
public:
    Solution() {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int x, y;
        for (int pt1 = 0, pt2 = 0; pt1 < n && pt2 < m;) {
            x = nums1[pt1];
            y = nums2[pt2];
            if (x == y) {
                return x;
            }
            if (x < y) {
                pt1++;
            }
            if (x > y) {
                pt2++;
            }
        }
        return -1;
    }
};