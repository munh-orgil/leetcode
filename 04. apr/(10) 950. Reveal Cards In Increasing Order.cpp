#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        vector<int> ret(n), idx = getIndices(n);
        for (int i = 0; i < n; i++) {
            cout << idx[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            ret[i] = deck[idx[i]];
        }
        return ret;
    }
    vector<int> getIndices(int n) {
        if (n == 1) {
            return { 0 };
        }
        if (n == 2) {
            return { 0, 1 };
        }
        int half = n / 2;
        vector<int> ret, vec = getIndices(half);
        if (n % 2) {
            for (int i = 0; i < half; i++) {
                ret.push_back(i);
                ret.push_back(vec[(i + half - 1) % half] + half + 1);
            }
            ret.push_back(half);
        }
        else {
            for (int i = 0; i < half; i++) {
                ret.push_back(i);
                ret.push_back(vec[i] + half);
            }
        }
        return ret;
    }
};
