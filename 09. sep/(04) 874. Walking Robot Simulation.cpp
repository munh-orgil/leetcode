#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector moveX = { 0, 1, 0, -1 };
        vector moveY = { 1, 0, -1, 0 };
        int dir = 0;
        int x = 0, y = 0;
        int ret = 0;
        int u, v, tmp;
        map<int, map<int, bool>> mp;
        for (auto ob : obstacles) {
            mp[ob[0]][ob[1]] = 1;
        }
        for (int cmd : commands) {
            switch (cmd) {
            case -2:
                dir = (dir + 3) % 4;
                break;
            case -1:
                dir = (dir + 1) % 4;
                break;
            default:
                for (int i = 0; i < cmd; i++) {
                    ret = max(ret, x * x + y * y);
                    u = x + moveX[dir];
                    v = y + moveY[dir];
                    if (mp[u][v]) {
                        break;
                    }
                    x = u; y = v;
                }
                break;
            }
        }
        ret = max(ret, x * x + y * y);
        return ret;
    }
};