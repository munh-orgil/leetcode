#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()

bool cmp(pair<int, int> x, pair<int, int> y) {
    return x.second > y.second;
}

class Solution {
public:
    string frequencySort(string s) {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);

        vector<pair<char, int>> cnt(62);
        int n = s.size();
        for (int i = 0; i < 10; i++) {
            cnt[i].first = '0' + i;
        }
        for (int i = 0; i < 26; i++) {
            cnt[i + 10].first = 'A' + i;
            cnt[i + 36].first = 'a' + i;
        }
        for (int i = 0; i < n; i++) {
            int x = s[i];
            if (x < 'A') {
                cnt[x - '0'].second++;
                continue;
            }
            if (x < 'a') {
                cnt[x - 'A' + 10].second++;
                continue;
            }
            cnt[x - 'a' + 36].second++;
        }
        sort(cnt.begin(), cnt.end(), cmp);
        string res = "";
        for (int i = 0; i < cnt.size(); i++) {
            for (int j = 0; j < cnt[i].second; j++) {
                res += cnt[i].first;
            }
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    auto sol = Solution{};
    auto res = sol.frequencySort(s);
    cout << res << endl;
}