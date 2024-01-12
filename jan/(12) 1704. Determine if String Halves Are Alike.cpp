#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()
#define ll long long

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size(), cnt;
        vector<char> vowels = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
        cnt = 0;
        for (int i = 0; i < n / 2; i++) {
            for (char ch : vowels) {
                if (s[i] == ch) {
                    cnt++;
                    break;
                }
            }
        }
        for (int i = n / 2; i < n; i++) {
            for (char ch : vowels) {
                if (s[i] == ch) {
                    cnt--;
                    break;
                }
            }
        }
        return !cnt;
    }
};

int main() {
    string s;
    cin >> s;
    Solution sol = Solution{};
    cout << sol.halvesAreAlike(s) << endl;
}