#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()
#define ll long long

class RandomizedSet {
public:
    unordered_map <int, bool> exist;
    RandomizedSet() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }

    bool insert(int val) {
        if (this->exist[val]) {
            return false;
        }
        return this->exist[val] = true;
    }

    bool remove(int val) {
        if (this->exist.erase(val)) {
            return true;
        }
        return false;
    }

    int getRandom() {
        auto it = this->exist.begin();
        advance(it, rand() % this->exist.size());
        return it->first;
    }
};

int main() {

    auto random = RandomizedSet();
    cout << random.insert(0) << endl;
    cout << random.remove(0) << endl;
    cout << random.insert(-1) << endl;
    cout << random.remove(0) << endl;
    for (auto m : random.exist) {
        cout << m.first << " -> " << m.second << endl;
    }
    cout << random.getRandom() << endl;
    cout << random.getRandom() << endl;
    cout << random.getRandom() << endl;
    cout << random.getRandom() << endl;
    cout << random.getRandom() << endl;
    cout << random.getRandom() << endl;
    cout << random.getRandom() << endl;
    cout << random.getRandom() << endl;
    cout << random.getRandom() << endl;
    cout << random.getRandom() << endl;
    cout << random.getRandom() << endl;

}