#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()

class Solution {
public:
    vector<int> intersection(const vector<int>& nums1, const vector<int>& nums2) {
        bool exist[1001] = {};
        int n = nums1.size();
        int m = nums2.size();
        for (int num : nums1) {
            exist[num] = true;
        }
        vector<int> ret;
        for (int num : nums2) {
            if (exist[num]) {
                ret.push_back(num);
                exist[num] = false;
            }
        }
        return ret;
    }
};