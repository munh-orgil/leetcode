#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    string reversePrefix(string word, char ch) {
        string::iterator it;
        for (it = word.begin(); it != word.end(); it++) {
            if (*it == ch) {
                break;
            }
        }
        if (it != word.end()) {
            reverse(word.begin(), it);
        }
        return word;
    }
};