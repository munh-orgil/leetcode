#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int longestPalindrome(string s) {
        int n = s.size();
        unordered_map<char, int> cnt;
        for (char ch : s) {
            cnt[ch]++;
        }
        bool hasOdd = 0;
        int ret = 0;
        for (auto [k, v] : cnt) {
            if (v % 2) {
                hasOdd = 1;
            }
            ret += v / 2 * 2;
        }
        return ret + hasOdd;
    }
};