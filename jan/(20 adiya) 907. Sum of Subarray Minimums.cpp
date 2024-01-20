#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()

class Solution {
public:
    const int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        vector < pair< int, int > > a;
        vector < vector < int > > b;
        vector < int > tmp;
        int n = arr.size();
        long long i, j, k, m, s, l, r;
        for (i = 0; i < n; i++) {
            a.push_back(make_pair(arr[i], i + 1));
        }
        sort(a.begin(), a.end());
        tmp.push_back(0);
        tmp.push_back(0);
        for (i = 0; i <= n + 1; i++) {
            tmp[0] = i - 1;
            tmp[1] = i + 1;
            b.push_back(tmp);
        }

        s = 0;
        for (i = n - 1;i >= 0;i--) {
            l = b[a[i].second][0];
            r = b[a[i].second][1];
            b[r][0] = l;
            b[l][1] = r;
            s = (s + (((r - a[i].second) % MOD) * ((a[i].second - l) % MOD) % MOD) * a[i].first % MOD) % MOD;
        }
        return s;
    }
};

int main() {
    int n;
    cin >> n;
    vector < int > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Solution sol = Solution{};
    cout << sol.sumSubarrayMins(a) << endl;
}