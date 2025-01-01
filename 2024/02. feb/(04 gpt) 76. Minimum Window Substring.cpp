#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> targetFreq, windowFreq;
        for (char c : t) {
            targetFreq[c]++;
        }
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int minStart = 0;
        int requiredChars = targetFreq.size();

        while (right < s.length()) {
            char currentChar = s[right];
            windowFreq[currentChar]++;
            if (targetFreq.count(currentChar) && windowFreq[currentChar] == targetFreq[currentChar]) {
                requiredChars--;
            }
            while (requiredChars == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                char leftChar = s[left];
                windowFreq[leftChar]--;
                if (targetFreq.count(leftChar) && windowFreq[leftChar] < targetFreq[leftChar]) {
                    requiredChars++;
                }
                left++;
            }
            right++;
        }
        if (minLen == INT_MAX) {
            return "";
        }
        return s.substr(minStart, minLen);
    }
};