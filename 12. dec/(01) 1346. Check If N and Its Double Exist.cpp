#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool checkIfExist(vector<int>& a) {
        int n = a.size();
        multiset<int> st(a.begin(), a.end());
        for (int i : st) {
            if ((st.count(i * 2) - (i == 0)) > 0) {
                return true;
            }
        }
        return false;
    }
};