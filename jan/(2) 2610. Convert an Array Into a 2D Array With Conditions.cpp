#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector <int> cnt(n + 1, 0);
        int mx = 0;
        for (int i : nums) {
            cnt[i]++;
            mx = max(mx, cnt[i]);
        }
        vector <vector <int>> res(mx, vector <int>());

        for (int num : nums) {
            res[cnt[num] - 1].push_back(num);
            cnt[num]--;
        }
        return res;
    }
};

int main() {
    Solution sol = Solution{};
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector <vector <int>> res = sol.findMatrix(a);
    for (int i = 0; i < res.size(); i++) {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << ",";
        }
        cout << "]\n";
    }
}
