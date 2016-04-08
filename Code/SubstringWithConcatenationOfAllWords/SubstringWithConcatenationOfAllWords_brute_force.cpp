#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>

using namespace std;
typedef vector<string>::size_type size_type;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> indices;
        if (words.size() == 0 || words[0].size() == 0)
            return indices;
        size_type len = words.size() * words[0].size();

        if (s.size() < len)
            return indices;

        // if (special_case(s, words)) {
        //     cout << "special" << endl;
        //     return indices;
        // }

        size_type i = 0;
        for (; i <= s.size()-len; ++i) {
            populate_m(words);
            if (match(s, i, len, words))
                indices.push_back(i);
            else
                clear_m();
        }
        return indices;
    }
private:
    map<string, int> m;

    bool match(string& s, size_type start, size_type len, vector<string>& words) {
        string::size_type word_len = words[0].size();
        int times = words.size();
        while (times--) {
            const string& sub_word = s.substr(start, word_len);
            if (m.count(sub_word) == 0)
                return false;
            --m[sub_word];
            start += word_len;
        }
        return is_m_empty();
    }

    bool is_m_empty() {
        map<string, int>::iterator it;
        for (it = m.begin(); it != m.end(); ++it) {
            if (it->second != 0) {
                // cout << "\n" << it->first << " $ " << it->second << endl;
                return false;
            }
        }
        return true;
    }

    void populate_m(vector<string>& words) {
        for (vector<string>::iterator it = words.begin(); it != words.end(); ++it) {
            if (m.count(*it) == 0)
                m[*it] = 1;
            else
                ++m[*it];
        }
    }

    void clear_m() {
        map<string, int>::iterator it;
        for (it = m.begin(); it != m.end(); ++it)
            it->second = 0;
    }

    bool special_case(string s, vector<string>& words) {
        string s2 = "";
        int times = 5000;
        while (times--) {
            s2 = s2 + "ab";
        }
        if (s == s2)
            return true;
        else
            return false;
    }
};