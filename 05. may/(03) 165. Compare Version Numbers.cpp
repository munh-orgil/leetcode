#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector < int > toNums(string s) {
        int n = s.size();
        vector < int > res;
        int num = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '.') {
                res.push_back(num);
                num = 0;
                continue;
            }
            num *= 10;
            num += (s[i] - '0');
        }
        res.push_back(num);
        return res;
    }
    int compareVersion(string version1, string version2) {
        vector < int > nums1 = toNums(version1);
        vector < int > nums2 = toNums(version2);
        int n = nums1.size();
        int m = nums2.size();
        while (n < m) {
            nums1.push_back(0);
            n++;
        }
        while (n > m) {
            nums2.push_back(0);
            m++;
        }
        for (int i = 0; i < n; i++) {
            if (nums1[i] == nums2[i]) {
                continue;
            }
            if (nums1[i] < nums2[i]) {
                return -1;
            }
            return 1;
        }
        return 0;
    }
};