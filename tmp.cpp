#include <bits/stdc++.h>

using namespace std;

int main() {
    string s = "asdqwe1234576_@!#$%NEWQKN";
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << " " << isdigit(s[i]) << " " << isupper(s[i]) << endl;
    }
    return 0;
}
