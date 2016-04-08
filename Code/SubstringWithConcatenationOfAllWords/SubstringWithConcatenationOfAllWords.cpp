// This version inspired by #76. Minimum Window Substring
// Discussion: https://leetcode.com/discuss/72701/here-10-line-template-that-can-solve-most-substring-problems

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        int n_words = words.size(), s_len = s.size(), word_len;
        if (s_len == 0 || n_words == 0 || (word_len = words[0].size()) == 0)
            return ret;

        int i, j, t, counter = n_words;
        map<string, int> m;
        

        for (t = 0; t < word_len; ++t, counter = n_words) {
            initialize_m(m, words);
            for (i = j = t; j <= s_len-word_len; j += word_len) {
                const string& word = s.substr(j, word_len);
                if (m.count(word) > 0 && m[word]-- > 0) {
                    --counter;
                }

                for (; counter == 0; i += word_len) {
                    if ((j-i)/word_len + 1 == n_words) {
                        ret.push_back(i);
                    }
                    const string& i_word = s.substr(i, word_len);
                    if (m.count(i_word) > 0 && m[i_word]++ == 0) {
                        ++counter;
                    }
                }
            }
        }

        return ret;
    }

    void initialize_m(map<string, int> &m, vector<string>& words) {
        m.clear();
        for (int i = 0; i < words.size(); ++i) {
            ++m[words[i]];
        }
    }
};

int main()
{
    Solution sol;
    vector<string> words = {"bar", "foo"};
    vector<int> result = sol.findSubstring("barfoothebarfoothe", words);
    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

