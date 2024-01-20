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
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> s1, s2;
        for (int i = 0; i < n; ++i) {
            while (!s1.empty() && arr[s1.top()] > arr[i]) {
                s1.pop();
            }
            left[i] = s1.empty() ? i + 1 : i - s1.top();
            s1.push(i);
        }
        for (int i = n - 1; i >= 0; --i) {
            while (!s2.empty() && arr[s2.top()] >= arr[i]) {
                s2.pop();
            }
            right[i] = s2.empty() ? n - i : s2.top() - i;
            s2.push(i);
        }
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum = (sum + (long long)arr[i] * left[i] * right[i]) % MOD;
        }

        return sum;
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