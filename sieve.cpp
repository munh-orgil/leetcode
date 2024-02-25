#include<bits/stdc++.h>

#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define ll long long
#define _ <<' '<<
#define mp make_pair
#define ALL(x) x.begin(), x.end()
#define LLA(x) x.rbegin(), x.rend()
#define PII pair < int , int >
#define PLL pair < ll , ll >
#define rep(i, a, n) for(int i = a ; i < n ; i++)
#define per(i, n, a) for(int i = n - 1 ; i >= a ; i--)
#define FOR(i, a, n) for(int i = a ; i <= n ; i++)
#define ROF(i, n, a) for(int i = n ; i >= a ; i--)
#define ins insert
#define CASE(POINTER) cout << "Case #" << POINTER << ": ";
#define BOOST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define readFile freopen("a.in", "w", stdout);
#define debug(n) cout << #n << " = " << n << endl;
#define VI vector < int >
#define VVI vector < VI >
#define VLL vector < ll >
#define VVLL vector < VLL >

using namespace std;

const int N = 3e5 + 7;
const int MOD = 1e9 + 7;
const int moveX[] = { -1, 0, 1, 0 };
const int moveY[] = { 0, 1, 0, -1 };
const int INFI = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1);

int main() {
    int n = 1e5;
    vector<int> p;
    vector<bool> b(n, 0);
    for (int i = 2; i <= sqrt(n); i++) {
        if (!b[i]) {
            p.push_back(i);
            for (int j = 1; i * j <= n; j++) {
                b[i * j] = 1;
            }
        }
    }
    for (int i = sqrt(n); i <= n; i++) {
        if (!b[i]) {
            p.push_back(i);
        }
    }
    for (int i = 0; i < p.size() - 1; i++) {
        cout << p[i] << ",";
    }
    cout << p[p.size() - 1] << endl;
}
