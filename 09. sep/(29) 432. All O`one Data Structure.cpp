#include<bits/stdc++.h>

using namespace std;

class AllOne {
public:
    unordered_map<string, int> mp;
    set<pair<int, string>> st;
    AllOne() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        mp.clear();
        st.clear();
    }

    void inc(string key) {
        int cnt = mp[key];
        mp[key]++;
        st.erase({ cnt, key });
        st.insert({ cnt + 1, key });
    }

    void dec(string key) {
        int cnt = mp[key];
        mp[key]--;
        st.erase({ cnt, key });
        if (cnt > 1) {
            st.insert({ cnt - 1, key });
        } else {
            mp.erase(key);
        }
    }

    string getMaxKey() {
        if (st.empty()) {
            return "";
        } else {
            return st.rbegin()->second;
        }
    }

    string getMinKey() {
        if (st.empty()) {
            return "";
        } else {
            return st.begin()->second;
        }
    }
};