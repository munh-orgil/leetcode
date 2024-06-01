#include <bits/stdc++.h>
using namespace std;

unordered_map<long long, long long> mp;

long long dfs(long long cur) {
    if (mp.find(cur) != mp.end()) {
        return mp[cur];
    }
    if (cur & 1) {
        mp[cur] = dfs(cur + (cur + 1) / 2) + 2;
        return mp[cur];
    }
    long long tmp = cur;
    while (tmp % 2 == 0) {
        tmp /= 2;
        if (mp.find(tmp) != mp.end()) {
            break;
        }
    }
    long long val = dfs(tmp);
    while (tmp < cur) {
        tmp *= 2;
        val++;
        mp[tmp] = val;
    }
    return mp[cur];
}

int main() {
    int t, n;
    cin >> t;

    mp[1] = 0;
    vector<int> ans(5e6 + 1, 0);
    for (int i = 2; i <= 5e6; i++) {
        dfs(i);
    }
    while (t--) {
        cin >> n;
        
    }
    return 0;
}
