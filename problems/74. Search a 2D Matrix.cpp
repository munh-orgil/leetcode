#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0, bot = n - 1;
        int left = 0, right = m - 1;
        int x = (top + bot) / 2, y = (left + right) / 2;
        while (top <= bot) {
            x = (top + bot) / 2;
            if (matrix[x][0] > target) {
                bot = x - 1;
            }
            else if (matrix[x][0] < target) {
                top = x + 1;
            }
            else {
                return true;
            }
        }
        while (x && matrix[x][0] > target) {
            x--;
        }
        while (left <= right) {
            y = (left + right) / 2;
            if (matrix[x][y] > target) {
                right = y - 1;
            }
            else if (matrix[x][y] < target) {
                left = y + 1;
            }
            else {
                return true;
            }
        }
        if (matrix[x][y] == target) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution sol = Solution{};
    int n, m, target;
    cin >> n >> m >> target;
    vector<vector<int>> a(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cout << sol.searchMatrix(a, target) << endl;
}