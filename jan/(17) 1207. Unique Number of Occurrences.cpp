#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()
#define ll long long

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        unordered_map<int, int> cnt, cnt2;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            cnt[arr[i]]++;
        }
        for (auto [k, v] : cnt) {
            cnt2[v]++;
            if (cnt2[v] > 1) {
                return false;
            }
        }
        return true;
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
    if (sol.uniqueOccurrences(a)) {
        cout << "true\n";
    }
    else {
        cout << "false\n";
    }
}