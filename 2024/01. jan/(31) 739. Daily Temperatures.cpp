#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<pair<int, int>> pt(n);
        for (int i = 0; i < n; i++) {
            pt[i] = { t[i], i };
        }
        vector<int> ret(n, 0);
        stack<pair<int, int>> st;
        st.push(pt[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && st.top().first <= pt[i].first) {
                st.pop();
            }
            if (!st.empty()) {
                ret[i] = st.top().second - i;
            }
            st.push(pt[i]);
        }
        return ret;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto sol = Solution{};
    auto res = sol.dailyTemperatures(a);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}