#include<bits/stdc++.h>

using namespace std;

class MyCalendar {
public:
    using PII = pair<int, int>;
    vector<PII> books;
    MyCalendar() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        books = vector<PII>();
    }

    bool book(int start, int end) {
        for (auto [st, en] : books) {
            if (st < end && en > start) {
                return false;
            }
        }
        books.push_back({ start, end });
        return true;
    }
};