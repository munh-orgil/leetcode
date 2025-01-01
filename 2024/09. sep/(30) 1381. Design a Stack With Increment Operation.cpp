#include<bits/stdc++.h>

using namespace std;

class CustomStack {
public:
    vector<int> v;
    int capacity, size;
    CustomStack(int maxSize) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        size = 0;
        capacity = maxSize;
        v = vector<int> (capacity, -1);
    }

    void push(int x) {
        if (size == capacity) {
            return;
        }
        v[size] = x;
        size++;
    }

    int pop() {
        if (!size) {
            return -1;
        }
        int ret = v[size - 1];
        v[size - 1] = -1;
        size--;
        return ret;
    }

    void increment(int k, int val) {
        k = min(k, size);
        for (int i = 0; i < k; i++) {
            v[i] += val;
        }
    }
};