#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()

#define VI vector < int >
#define VVI vector < VI >
#define VVVI vector < VVI >

class Solution {
public:
    vector<int> sieve = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317 };
    unordered_map<int, vector<int>> divisors;
    unordered_map<int, int> adj;
    bool canTraverseAllPairs(vector<int>&nums) {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);

        int n = nums.size();
        if (n == 1) {
            return true;
        }
        set<int> primes;

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (divisors[num].size() > 0) {
                continue;
            }
            if (num == 1) {
                return false;
            }
            for (int p : sieve) {
                if (p > num) {
                    break;
                }
                if (num % p == 0) {
                    primes.insert(p);
                    divisors[nums[i]].push_back(p);
                    while (num % p == 0) {
                        num /= p;
                    }
                }
            }
            if (num > 1) {
                primes.insert(num);
                divisors[nums[i]].push_back(num);
            }
        }
        // cout << "primes\n";
        // for (int elem : primes) {
        //     cout << elem << " ";
        // }
        // cout << endl;
        int p = primes.size();
        for (int elem : primes) {
            adj[elem] = elem;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < divisors[nums[i]].size(); j++) {
                merge(divisors[nums[i]][0], divisors[nums[i]][j]);
            }
        }
        // cout << "adj:\n";
        // for (auto [k, v] : adj) {
        //     cout << k _ v _ find(v) << endl;
        // }
        int x = find(*primes.begin());
        for (int elem : primes) {
            if (x != find(elem)) {
                return false;
            }
        }
        return true;
    }

    int find(int x) {
        if (adj[x] == x) {
            return x;
        }
        return adj[x] = find(adj[x]);
    }
    void merge(int x, int y) {
        adj[find(x)] = find(y);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution sol = Solution{};
    string res = sol.canTraverseAllPairs(nums) ? "true" : "false";
    cout << res << endl;
}