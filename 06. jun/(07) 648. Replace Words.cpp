#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    bool check(string word, string dic) {
        return word.substr(0, dic.size()) == dic;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        int n = dictionary.size();
        sort(dictionary.begin(), dictionary.end(), [&](string x, string y) {
            return x.size() < y.size();
            });

        int m = sentence.size();
        string word = "";
        vector<string> words;
        for (int i = 0; i < m; i++) {
            if (sentence[i] == ' ') {
                words.push_back(word);
                word = "";
                continue;
            }
            word += sentence[i];
        }
        words.push_back(word);

        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < n; j++) {
                if (dictionary[j].size() > words[i].size()) {
                    break;
                }
                if (check(words[i], dictionary[j])) {
                    words[i] = dictionary[j];
                    break;
                }
            }
        }

        string ret = "";
        for (int i = 0; i < words.size() - 1; i++) {
            ret += words[i] + " ";
        }
        ret += words[words.size() - 1];

        return ret;
    }
};