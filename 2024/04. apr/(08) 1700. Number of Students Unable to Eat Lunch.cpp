#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int m = sandwiches.size();
        int sum[2] = { 0 };
        for (int st : students) {
            sum[st]++;
        }
        int pt = 0;
        for (int i = 0; i < students.size(); i++) {
            if (pt == m) {
                return 0;
            }
            if (students[i] == sandwiches[pt]) {
                sum[sandwiches[pt]]--;
                pt++;
                continue;
            }
            if (!sum[sandwiches[pt]]) {
                return sum[1 - sandwiches[pt]];
            }
            students.push_back(students[i]);
        }
        return 0;
    }
};
