#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                if (i > 0 && s[i - 1] == ' ') {
                    cnt = 0;
                }
                cnt++;
            }
        }
        return cnt;
    }
};