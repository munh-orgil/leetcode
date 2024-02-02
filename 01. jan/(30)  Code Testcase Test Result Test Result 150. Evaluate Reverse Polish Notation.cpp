#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()

class Solution {
public:
    vector<string> operands = { "+", "-", "*", "/" };
    int CheckOperand(string s) {
        for (int i = 0; i < 4; i++) {
            if (s == operands[i]) {
                return i + 1;
            }
        }
        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);

        stack<int> st;
        int n = tokens.size();
        for (int i = 0; i < n; i++) {
            int op = CheckOperand(tokens[i]);
            if (op) {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                switch (op) {
                case 1:
                    st.push(num1 + num2);
                    break;
                case 2:
                    st.push(num1 - num2);
                    break;
                case 3:
                    st.push(num1 * num2);
                    break;
                case 4:
                    st.push(num1 / num2);
                    break;
                }
            }
            else {
                int num = 0;
                bool positive = true;
                for (auto x : tokens[i]) {
                    if (x == '-') {
                        positive = false;
                        continue;
                    }
                    num = num * 10 + x - '0';
                }
                if (!positive) {
                    num *= -1;
                }
                st.push(num);
            }
        }
        return st.top();
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> tokens(n);
    for (int i = 0; i < n; i++) {
        cin >> tokens[i];
    }
    auto sol = Solution{};
    auto res = sol.evalRPN(tokens);
    debug(res);
}