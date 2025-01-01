#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()
#define ll long long

class Solution {
public:
    int climbStairs(int n) {
        int a = 1;
        int b = 1;
        for (int i = 0; i < n; i++) {
            b += a;
            a = b - a;
        }
        cout << b << endl;
    }
};