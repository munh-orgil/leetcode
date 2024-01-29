#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()

class MyQueue {
public:
    stack<int> st1, st2;
    MyQueue() {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);
    }

    void push(int x) {
        st1.push(x);
    }

    int pop() {
        while (st1.size() > 1) {
            st2.push(st1.top());
            st1.pop();
        }
        int res = st1.top();
        st1.pop();
        while (st2.size()) {
            st1.push(st2.top());
            st2.pop();
        }
        return res;
    }

    int peek() {
        while (st1.size() > 1) {
            st2.push(st1.top());
            st1.pop();
        }
        int res = st1.top();
        while (st2.size()) {
            st1.push(st2.top());
            st2.pop();
        }
        return res;
    }

    bool empty() {
        return !st1.size();
    }
};