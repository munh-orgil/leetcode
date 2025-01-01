#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> pool;
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[i - 1]) {
                pool.push_back(cnt);
                cnt = 1;
                continue;
            }
            cnt++;
        }
        pool.push_back(cnt);
        sort(pool.begin(), pool.end());
        for (int i = 0; i < pool.size(); i++) {
            if (k >= pool[i]) {
                k -= pool[i];
                continue;
            }
            return pool.size() - i;
        }
        return 0;
    }
};

int main() {
    int n, k;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> k;
    Solution sol = Solution{};
    auto res = sol.findLeastNumOfUniqueInts(a, k);
    cout << res << endl;
}