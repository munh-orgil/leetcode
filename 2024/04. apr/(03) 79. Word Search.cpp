#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<char>> board;
    vector<vector<bool>> vis;
    string word;
    const int moveX[4] = { -1, 0, 1, 0 };
    const int moveY[4] = { 0, 1, 0, -1 };
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        this->word = word;
        int n = board.size();
        int m = board[0].size();
        vis.resize(n, vector<bool> (m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && search(i, j, 1)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool search(int x, int y, int idx) {
        vis[x][y] = true;
        if (idx == word.size()) {
            return true;
        }
        int u, v;
        for (int i = 0; i < 4; i++) {
            u = x + moveX[i];
            v = y + moveY[i];
            if (u < 0 || u >= board.size() || v < 0 || v >= board[0].size() || vis[u][v]) {
                continue;
            }
            if (board[u][v] == word[idx]) {
                if (search(u, v, idx + 1)) {
                    return true;
                }
            }
        }
        vis[x][y] = false;
        return false;
    }
};