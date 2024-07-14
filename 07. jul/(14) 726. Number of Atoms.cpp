#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int toInt(string& s) {
        if (s == "") {
            return 1;
        }
        int ret = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            ret = ret * 10 + s[i] - '0';
        }
        return ret;
    }
    pair<string, int> divide(string& elem) {
        string num = "";
        string tmp = "";
        for (char c : elem) {
            if (isdigit(c)) {
                num.push_back(c);
            } else {
                tmp.push_back(c);
            }
        }
        return { tmp, toInt(num) };
    }
    string countOfAtoms(string& s) {
        int n = s.size();
        map<string, int> cnt;
        stack<pair<string, int>> st, st2;
        string elem = "", tmp;
        int mult, j;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                if (elem != "") {
                    st.push(divide(elem));
                    elem = "";
                }
                st.push({ string(1, s[i]), 0 });
                continue;
            }
            if (s[i] == ')') {
                if (elem != "") {
                    st.push(divide(elem));
                    elem = "";
                }
                j = i + 1;
                tmp = "";
                while (j < n && isdigit(s[j])) {
                    tmp.push_back(s[j]);
                    j++;
                }
                i = j - 1;
                mult = toInt(tmp);
                while (!st.empty()) {
                    auto top = st.top();
                    st.pop();
                    if (top.first == "(") {
                        break;
                    }
                    top.second *= mult;
                    st2.push(top);
                }
                while (!st2.empty()) {
                    st.push(st2.top());
                    st2.pop();
                }
                continue;
            }
            if (isupper(s[i])) {
                if (elem != "") {
                    st.push(divide(elem));
                    elem = "";
                }
                elem = string(1, s[i]);
                continue;
            }
            elem += s[i];
        }
        if (elem != "") {
            auto [k, v] = divide(elem);
            cnt[k] += v;
        }
        while (!st.empty()) {
            auto [k, v] = st.top();
            st.pop();
            cnt[k] += v;
        }
        string ret = "";
        string val;
        for (auto [k, v] : cnt) {
            ret += k;
            if (v > 1) {
                val = "";
                while (v) {
                    val.push_back(char(v % 10 + '0'));
                    v /= 10;
                }
                reverse(val.begin(), val.end());
                ret += val;
            }
        }
        return ret;
    }
};

int main() {
    string s;
    cin >> s;
    auto sol = Solution{};
    cout << sol.countOfAtoms(s) << endl;
}