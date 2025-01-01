#include<bits/stdc++.h>

using namespace std;

#define _ << " " <<
class MyCalendarTwo {
public:
    using TI = tuple<int, int, int>;
    vector<TI> books;
    MyCalendarTwo() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        books = vector<TI>();
    }

    bool book(int start, int end) {
        cout << start _ end << ":\n";
        for (auto [s, e, cnt] : books) {
            cout << s _ e _ cnt << endl;
            if (s >= end || e <= start) {
                continue;
            }
            if (cnt == 2) {
                return false;
            }
        }
        int n = books.size();
        bool intersect = 0;
        for (int i = 0; i < n; i++) {
            auto [s, e, cnt] = books[i];
            if (s >= end || e <= start) {
                continue;
            }
            intersect = 1;
            books.push_back({ min(s, start), max(s, start), 1 });
            books.push_back({ max(s, start), min(e, end), 2 });
            books.push_back({ min(e, end), max(e, end), 1 });
        }
        for (int i = 0; i < n; i++) {
            auto [s, e, cnt] = books[i];
            if (s < end && e > start) {
                books.erase(books.begin() + i);
            }
        }
        if (!intersect) books.push_back({ start, end, 1 });
        return true;
    }
};