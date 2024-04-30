#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    long long wonderfulSubstrings(const string word) {
        int n = word.size();
        vector<int> preSum(10, 0);
        vector<int> cnt(2000, 0), nums(n, 0);
        cnt[0]++;
        long long ret = 0;
        for (int i = 0; i < n; i++) {
            preSum[word[i] - 'a'] = 1 - preSum[word[i] - 'a'];
            for (int j = 0; j < 10; j++) {
                if (preSum[j]) {
                    nums[i] += 1 << j;
                }
            }
            ret += cnt[nums[i]];
            int x = 1;
            for (int j = 0; j < 10; j++) {
                ret += cnt[nums[i] ^ x];
                x *= 2;
            }
            cnt[nums[i]]++;
        }
        return ret;
    }
};