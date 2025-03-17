#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool divideArray(vector<int>& a) {
        vector<int> cnt(*max_element(a.begin(), a.end()) + 1, 0);
        for (int i : a) {
            cnt[i] = (cnt[i] + 1) % 2;
        }
        for (int i : cnt) {
            if (i > 0) {
                return false;
            }
        }
        return true;
    }
};