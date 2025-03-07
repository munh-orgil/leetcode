#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        Sieve();
    }
    set<int> primes;
    void Sieve() {
        const int N = 1e6;
        vector<bool> inc(N);
        for (int i = 2; i < sqrt(N); i++) {
            if (inc[i]) continue;
            primes.insert(i);
            for (int j = 1; i * j < N; j++) {
                inc[i * j] = 1;
            }
        }
        for (int i = sqrt(N); i < N; i++) {
            if (!inc[i]) primes.insert(i);
        }
    }
    vector<int> closestPrimes(int l, int r) {
        if (l <= 2 && r >= 3) {
            return { 2, 3 };
        }
        vector<int> ret(2, -1);
        auto a = primes.lower_bound(l);
        if (a == primes.end()) {
            return ret;
        }
        auto b = next(a);
        if (b == primes.end()) {
            return ret;
        }
        int mn = 1e9;
        while (*b <= r) {
            if (*b - *a < mn) {
                mn = *b - *a;
                ret = { *a, *b };
            }
            a = next(a);
            b = next(b);
        }
        return ret;
    }
};