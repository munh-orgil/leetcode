#include<bits/stdc++.h>

using namespace std;

#define _ << " " <<

class MyCircularDeque {
public:
    int capacity;
    int size;
    int front;
    int back;
    vector<int> items;
    MyCircularDeque(int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        capacity = k;
        size = 0;
        front = 0;
        back = 0;
        items = vector<int>(k, -1);
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        front = (front - 1 + capacity) % capacity;
        items[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        items[back] = value;
        back = (back + 1) % capacity;
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        items[front] = -1;
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        back = (back - 1 + capacity) % capacity;
        items[back] = -1;
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return items[front];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return items[(back - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};