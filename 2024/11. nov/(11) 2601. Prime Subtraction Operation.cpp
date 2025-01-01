#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> primes;
    void Sieve() {
        int n = 1000;
        vector<bool> incl(n);
        for (int i = 2; i < sqrt(n); i++) {
            if (!incl[i]) {
                primes.push_back(i);
                for (int j = 1; i * j < n; j++) {
                    incl[i * j] = 1;
                }
            }
        }
        for (int i = sqrt(n); i < n; i++) {
            if (!incl[i]) primes.push_back(i);
        }
    }
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        Sieve();
    }
    bool primeSubOperation(vector<int>& a) {
        int n = a.size();
        bool ok = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] <= a[i - 1]) {
                ok = 0;
                break;
            }
        }
        if (ok) return true;
        int prev = 0;
        for (int i = 0; i < n; i++) {
            int idx = lower_bound(primes.begin(), primes.end(), a[i]) - primes.begin();
            while (idx >= int(primes.size()) || (idx >= 0 && a[i] - primes[idx] <= prev)) {
                idx--;
            }
            if (idx < 0) {
                return false;
            }
            a[i] -= primes[idx];
            prev = a[i];
        }
        return true;
    }
};